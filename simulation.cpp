#include "simulation.h"
#include "ui_dialog.h"
#include <QRandomGenerator>
#include <QDebug>

Simulation::Simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    isPaused(false),
    isGameRunning(false),
    blueScore(0),
    goalProcessed(false) // Ensure it's initially false
{
    ui->setupUi(this);

    // Set the field image as the background
    ui->FieldLabel->setStyleSheet("border-image: url(C:/Users/AMEN WORKSTATION/Downloads/360_F_293127241_bMzrEAk3zhehEnsLw6y4k3HfFewopUPG.jpg);");

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Simulation::updatePositions);

    saveInitialPositions(); // Save initial positions for reset
}

Simulation::~Simulation() {
    delete ui;
}

void Simulation::on_Start_clicked() {
    if (!isGameRunning) {
        timer->start(100);  // Update every 100ms
        isGameRunning = true;
        isPaused = false;
        qDebug() << "Game starting!";
    }
}

void Simulation::on_Resume_clicked() {
    isPaused = false;
    qDebug() << "Game resumed!";
}

void Simulation::on_Pause_clicked() {
    isPaused = true;
    qDebug() << "Game paused!";
}

void Simulation::updatePositions() {
    if (isPaused || !isGameRunning) return;

    movePlayersTowardsBall();
    checkGoalScored();
}

void Simulation::movePlayersTowardsBall() {
    QLabel *ball = ui->Ball;
    int ballX = ball->x();
    int ballY = ball->y();

    for (int i = 2; i <= 11; ++i) {
        QLabel *player = findChild<QLabel*>(QString("Player%1").arg(i));

        if (player) {
            int moveX = (ballX > player->x()) ? 5 : -5;
            int moveY = (ballY > player->y()) ? 5 : -5;

            player->move(player->x() + moveX, player->y() + moveY);
        }
    }

    moveAttackers();
}

void Simulation::moveAttackers() {
    QLabel *goal = ui->GOAL;
    int goalX = goal->x();
    int goalY = goal->y();

    for (int i = 9; i <= 11; ++i) {
        QLabel *attacker = findChild<QLabel*>(QString("Player%1").arg(i));

        if (attacker && ui->Ball->geometry().intersects(attacker->geometry())) {
            int moveX = (goalX > attacker->x()) ? 10 : -10;
            int moveY = (goalY > attacker->y()) ? 3 : -3;

            attacker->move(attacker->x() + moveX, attacker->y() + moveY);
            ui->Ball->move(attacker->x(), attacker->y());

            if (qAbs(attacker->x() - goalX) < 50) {
                shootBall(attacker);
            }
        }
    }
}

void Simulation::shootBall(QLabel *shooter) {
    QLabel *goal = ui->GOAL;

    bool isMiss = (QRandomGenerator::global()->bounded(2) == 0); // 50% chance to miss

    if (isMiss) {
        int missOffsetX = QRandomGenerator::global()->bounded(-50, 50); // Slightly left/right
        int missOffsetY = QRandomGenerator::global()->bounded(20, 80); // Slightly above/below
        ui->Ball->move(goal->x() + missOffsetX, goal->y() + missOffsetY); // Near miss
        qDebug() << shooter->objectName() << " shoots! Missed!";

        // Reset everything immediately after missing
        QTimer::singleShot(500, this, &Simulation::resetGame);
        return;
    }

    // If it's not a miss, move ball to goal and check for scoring
    ui->Ball->move(goal->x(), goal->y());
    qDebug() << shooter->objectName() << " shoots! Goal attempt!";
    checkGoalScored();
}



void Simulation::checkGoalScored() {
    if (goalProcessed) return; // Prevent multiple counts

    if (ui->Ball->geometry().intersects(ui->GOAL->geometry())) {
        qDebug() << "GOAL for Blue Team!";
        blueScore++;
        ui->scoreb->setText(QString::number(blueScore));
        goalProcessed = true;

        // Delay reset to make shot visible
        QTimer::singleShot(500, this, &Simulation::resetGame);
    }
}



void Simulation::saveInitialPositions() {
    QList<QLabel*> elements = findChildren<QLabel*>();
    for (QLabel *element : elements) {
        initialPositions[element] = element->pos();
    }
}

void Simulation::resetGame() {
    for (auto it = initialPositions.begin(); it != initialPositions.end(); ++it) {
        it.key()->move(it.value());
    }

    goalProcessed = false; // Reset goal processing
    isGameRunning = false;
    timer->stop();
    qDebug() << "Game reset! Ready for next attack.";
}
