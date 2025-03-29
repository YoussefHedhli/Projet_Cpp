#include "simulation.h"
#include "ui_dialog.h"
#include <QRandomGenerator>
#include <QDebug>

Simulation::Simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    isPaused(false),
    isGameRunning(false)
{
    ui->setupUi(this);

    // Set the field image as the background
    ui->FieldLabel->setStyleSheet("border-image: url(C:/Users/AMEN WORKSTATION/Downloads/360_F_293127241_bMzrEAk3zhehEnsLw6y4k3HfFewopUPG.jpg);");

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Simulation::updatePositions);
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

    // Move players dynamically toward the ball
    for (int i = 2; i <= 11; ++i) {
        QLabel *player = findChild<QLabel*>(QString("Player%1").arg(i));

        if (player) {
            int moveX = (ballX > player->x()) ? 5 : -5;
            int moveY = (ballY > player->y()) ? 5 : -5;

            player->move(player->x() + moveX, player->y() + moveY);
        }
    }

    // If attackers (Player9, Player10, Player11) reach the ball, move toward goal
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
            ui->Ball->move(attacker->x(), attacker->y()); // Ball follows the attacker

            if (qAbs(attacker->x() - goalX) < 50) {
                decideShotOutcome(attacker);
            }
        }
    }
}

void Simulation::decideShotOutcome(QLabel *shooter) {
    bool shotOnTarget = QRandomGenerator::global()->bounded(2); // 50% chance of goal or miss

    if (shotOnTarget) {
        shootBall(shooter);
    } else {
        missShot(shooter);
    }
}

void Simulation::shootBall(QLabel *shooter) {
    QLabel *goal = ui->GOAL;
    ui->Ball->move(goal->x(), goal->y());

    qDebug() << shooter->objectName() << " shoots! Goal attempt!";
    checkGoalScored();
}

void Simulation::missShot(QLabel *shooter) {
    int missX = shooter->x() + QRandomGenerator::global()->bounded(50, 100); // Randomly far from goal
    int missY = shooter->y() + QRandomGenerator::global()->bounded(-30, 30); // Slight variation in height
    ui->Ball->move(missX, missY);

    qDebug() << shooter->objectName() << " shoots! Missed shot!";
    timer->stop();
    isGameRunning = false;
}

void Simulation::checkGoalScored() {
    if (ui->Ball->geometry().intersects(ui->GOAL->geometry())) {
        qDebug() << "GOAL for Blue Team!";
        timer->stop();
        isGameRunning = false;
    } else if (ui->Ball->geometry().intersects(ui->GOAL1->geometry())) {
        qDebug() << "GOAL for Red Team!";
        timer->stop();
        isGameRunning = false;
    }
}
