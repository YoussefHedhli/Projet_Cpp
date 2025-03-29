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
    redScore(0),
    goalProcessed(false),
    isBlueTurn(true) // Blue team starts first
{
    ui->setupUi(this);
    ui->FieldLabel->setStyleSheet("border-image: url(C:/Users/AMEN WORKSTATION/Downloads/360_F_293127241_bMzrEAk3zhehEnsLw6y4k3HfFewopUPG.jpg);");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Simulation::updatePositions);
    saveInitialPositions();
}

Simulation::~Simulation() {
    delete ui;
}

void Simulation::on_Start_clicked() {
    if (!isGameRunning) {
        timer->start(100);
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

    if (isBlueTurn) {
        movePlayersTowardsBall(2, 11);
        moveAttackers(9, 11, ui->GOAL);
    } else {
        movePlayersTowardsBall(12, 21);
        moveRedAttackers();
    }
    checkGoalScored();
}

void Simulation::movePlayersTowardsBall(int start, int end) {
    QLabel *ball = ui->Ball;
    int ballX = ball->x();
    int ballY = ball->y();

    for (int i = start; i <= end; ++i) {
        QLabel *player = findChild<QLabel*>(QString("Player%1").arg(i));
        if (player) {
            int moveX = (ballX > player->x()) ? 5 : -5;
            int moveY = (ballY > player->y()) ? 5 : -5;
            player->move(player->x() + moveX, player->y() + moveY);
        }
    }
}

void Simulation::moveAttackers(int start, int end, QLabel *goal) {
    for (int i = start; i <= end; ++i) {
        QLabel *attacker = findChild<QLabel*>(QString("Player%1").arg(i));
        if (attacker && ui->Ball->geometry().intersects(attacker->geometry())) {
            int moveX = (goal->x() > attacker->x()) ? 10 : -10;
            int moveY = (goal->y() > attacker->y()) ? 3 : -3;
            attacker->move(attacker->x() + moveX, attacker->y() + moveY);
            ui->Ball->move(attacker->x(), attacker->y());
            if (qAbs(attacker->x() - goal->x()) < 50) {
                shootBall(attacker, goal);
            }
        }
    }
}

void Simulation::moveRedAttackers() {
    QLabel *goal = ui->GOAL1;
    QLabel *ball = ui->Ball;
    QLabel *midfielder = ui->Player15; // Start pass from midfield
    QLabel *winger = ui->Player13;
    QLabel *striker = ui->Player12;

    if (ball->geometry().intersects(midfielder->geometry())) {
        passBall(midfielder, winger->x(), winger->y());
    } else if (ball->geometry().intersects(winger->geometry())) {
        passBall(winger, striker->x(), striker->y());
    } else if (ball->geometry().intersects(striker->geometry())) {
        shootBall(striker, goal);
    }
}

void Simulation::passBall(QLabel *player, int ballX, int ballY) {
    ui->Ball->move(ballX, ballY);
}

void Simulation::shootBall(QLabel *shooter, QLabel *goal) {
    bool isMiss = (QRandomGenerator::global()->bounded(2) == 0);
    if (isMiss) {
        int missOffsetX = QRandomGenerator::global()->bounded(-50, 50);
        int missOffsetY = QRandomGenerator::global()->bounded(20, 80);
        ui->Ball->move(goal->x() + missOffsetX, goal->y() + missOffsetY);
        qDebug() << shooter->objectName() << " shoots! Missed!";
        QTimer::singleShot(500, this, &Simulation::resetGame);
        return;
    }
    ui->Ball->move(goal->x(), goal->y());
    qDebug() << shooter->objectName() << " shoots! Goal attempt!";
    checkGoalScored();
}

void Simulation::checkGoalScored() {
    if (goalProcessed) return;
    QLabel *goal = isBlueTurn ? ui->GOAL : ui->GOAL1;
    QLabel *scoreLabel = isBlueTurn ? ui->scoreb : ui->scorer;
    int &teamScore = isBlueTurn ? blueScore : redScore;

    if (ui->Ball->geometry().intersects(goal->geometry())) {
        qDebug() << "GOAL!";
        teamScore++;
        scoreLabel->setText(QString::number(teamScore));
        goalProcessed = true;
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
    goalProcessed = false;
    isGameRunning = false;
    timer->stop();
    isBlueTurn = !isBlueTurn;
    qDebug() << "Game reset!";
    QTimer::singleShot(500, this, &Simulation::on_Start_clicked);
}
