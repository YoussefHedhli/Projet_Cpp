#include "simulation.h"
#include "ui_dialog.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QSoundEffect>

Simulation::Simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    isPaused(false),
    isGameRunning(false),
    blueScore(0),
    redScore(0),
    goalProcessed(false),
    isBlueTurn(true), // Blue team starts first
    matchTime(15)// 15 seconds match time

{
    ui->setupUi(this);
    ui->FieldLabel->setStyleSheet("border-image: url(C:/Users/AMEN WORKSTATION/Downloads/360_F_293127241_bMzrEAk3zhehEnsLw6y4k3HfFewopUPG.jpg);");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Simulation::updatePositions);
    saveInitialPositions();
    matchTimer = new QTimer(this);
    connect(matchTimer, &QTimer::timeout, this, &Simulation::updateMatchTime);
    matchTime = 15;  // Set match duration to 15 seconds
    ui->chrono->display(matchTime); // Initialize LCD display

}

Simulation::~Simulation() {
    delete ui;
}

void Simulation::paintEvent(QPaintEvent *event)
{
    // Load background image
    QPixmap pix("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/bg.jpg");  // Use resource path if image is part of Qt resource system
    if (pix.isNull()) {
        qDebug() << "Failed to load bg.jpg. Check the file path.";
    } else {
        // Scale the image to fit the size of the label
        ui->label_pic->setPixmap(pix.scaled(900, 1000, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    QPixmap logoPix("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/ball.png");  // Assuming the logo is also stored as a resource
    if (logoPix.isNull()) {
        qDebug() << "Failed to load logo.png. Check the file path.";
    } else {
        // Scale the logo to a desired size
        ui->ball->setPixmap(logoPix.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }


    // Optionally, you can also use QPainter for other custom drawing if needed
    QDialog::paintEvent(event);  // Ensure the parent class paintEvent is called
}

void Simulation::on_Start_clicked() {
    if (!isGameRunning) {
        timer->start(100);  // Start player movement timer
        matchTime = 15;  // Reset match time to 15 seconds
        ui->chrono->display(matchTime);  // Update LCD display
        matchTimer->start(1000);  // Start match timer (counts every second)
        isGameRunning = true;
        isPaused = false;
        qDebug() << "Game starting!";
    }
}
void Simulation::updateMatchTime() {
    if (matchTime > 0) {
        matchTime--;  // Decrease time
        ui->chrono->display(matchTime);  // Update LCD display
    }

    if (matchTime == 0) {  // Match ends after 15 seconds
        matchTimer->stop();  // Stop countdown
        timer->stop();  // Stop player movement
        isGameRunning = false;
        qDebug() << "Match Over!";
        resetGame();  // Now reset everything
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
        moveDefenders(12, 16, ui->Ball);  // Red team defends
    } else {
        movePlayersTowardsBall(12, 21);
        moveRedAttackers();
        moveDefenders(2, 6, ui->Ball);  // Blue team defends
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

void Simulation::moveDefenders(int start, int end, QLabel *target) {
    for (int i = start; i <= end; ++i) {
        QLabel *defender = findChild<QLabel*>(QString("Player%1").arg(i));
        if (defender) {
            int ballX = target->x();
            int ballY = target->y();
            int defX = defender->x();
            int defY = defender->y();

            int moveX = 0, moveY = 0;

            // Calculate direction toward ball
            int dx = ballX - defX;
            int dy = ballY - defY;

            float distance = std::sqrt(dx * dx + dy * dy);
            float speedFactor = QRandomGenerator::global()->bounded(15, 36) / 10.0f; // ✅ Correct and clear
             // vary speed for realism

            if (distance > 0) {
                moveX = static_cast<int>((dx / distance) * speedFactor);
                moveY = static_cast<int>((dy / distance) * speedFactor);
            }

            // Simulate repositioning: defenders adjust their shape occasionally
            if (QRandomGenerator::global()->bounded(10) < 3) { // 30% chance
                moveX += QRandomGenerator::global()->bounded(-2, 3);
                moveY += QRandomGenerator::global()->bounded(-2, 3);
            }

            // Add slight unpredictability
            if (QRandomGenerator::global()->bounded(100) < 5) { // 5% rare sudden shift
                moveX += QRandomGenerator::global()->bounded(-4, 5);
                moveY += QRandomGenerator::global()->bounded(-4, 5);
            }

            defender->move(defX + moveX, defY + moveY);
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
    QLabel *players[] = {ui->Player12, ui->Player13, ui->Player14, ui->Player15, ui->Player16};
    static int passStage = 0;
    static bool isPassing = true;

    QLabel *currentPasser = players[passStage];
    QLabel *nextPasser = (passStage < 4) ? players[passStage + 1] : nullptr;

    int shootingRange = goal->x() - 100; // Ensure they only shoot near the goal

    // If still passing and next player is available
    if (isPassing && nextPasser) {
        moveBallTowards(nextPasser->x(), nextPasser->y());

        // When the ball reaches the next player, update pass stage
        if (qAbs(ball->x() - nextPasser->x()) < 10 && qAbs(ball->y() - nextPasser->y()) < 10) {
            isPassing = false;
            passStage++;
        }
    }
    // When the last attacker gets the ball, check if it's time to shoot
    else if (passStage == 4) {
        QLabel *finalAttacker = players[4];

        if (finalAttacker->x() >= shootingRange) { // If close enough, shoot
            shootBall(finalAttacker, goal);
            passStage = 0;
            isPassing = true;
        } else {
            movePlayerTowardsGoal(finalAttacker); // Move closer before shooting
        }
    } else {
        isPassing = true;
    }
}

void Simulation::moveBallTowards(int targetX, int targetY) {
    QLabel *ball = ui->Ball;
    int moveX = (targetX > ball->x()) ? 5 : -5;
    int moveY = (targetY > ball->y()) ? 3 : -3;
    ball->move(ball->x() + moveX, ball->y() + moveY);
}

void Simulation::passBall(QLabel *player, int ballX, int ballY) {
    int moveX = (ballX > player->x()) ? 10 : -10;
    int moveY = (ballY > player->y()) ? 5 : -5;
    player->move(player->x() + moveX, player->y() + moveY);
    ui->Ball->move(player->x(), player->y());
}

void Simulation::movePlayerTowardsGoal(QLabel *player) {
    QLabel *goal = ui->GOAL1;
    int moveX = (goal->x() > player->x()) ? 5 : -5;  // Move forward step by step
    int moveY = (goal->y() > player->y()) ? 2 : -2;
    player->move(player->x() + moveX, player->y() + moveY);
    ui->Ball->move(player->x(), player->y()); // Ball follows last attacker
}

void Simulation::shootBall(QLabel *shooter, QLabel *goal) {
    bool isMiss = (QRandomGenerator::global()->bounded(2) == 0);
    if (isMiss) {
        int missOffsetX = QRandomGenerator::global()->bounded(-50, 50);
        int missOffsetY = QRandomGenerator::global()->bounded(20, 80);
        ui->Ball->move(goal->x() + missOffsetX, goal->y() + missOffsetY);
        QTimer::singleShot(500, this, &Simulation::switchTurn);
        return;
    }
    ui->Ball->move(goal->x(), goal->y());
    checkGoalScored();
}

void Simulation::checkGoalScored() {
    if (goalProcessed) return;
    QLabel *goal = isBlueTurn ? ui->GOAL : ui->GOAL1;
    QLabel *scoreLabel = isBlueTurn ? ui->scoreb : ui->scorer;
    int &score = isBlueTurn ? blueScore : redScore;

    if (ui->Ball->geometry().intersects(goal->geometry())) {
        score++;
        scoreLabel->setText(QString::number(score));
        goalProcessed = true;
        QTimer::singleShot(500, this, &Simulation::switchTurn);
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
        it.key()->move(it.value());  // Reset player positions
    }
    goalProcessed = false;
    isGameRunning = false;
    timer->stop();  // Stop player movement only, NOT the match timer
}




void Simulation::switchTurn() {
    resetGame();  // Reset players' positions but don't stop the match timer

    QTimer::singleShot(1000, this, [this]() {
        isBlueTurn = !isBlueTurn;  // Switch team turn
        isGameRunning = true;
        isPaused = false;
        timer->start(100);
        qDebug() << "Switching turn!";
    });

    // 🔥 Ensure the match timer keeps running
    if (!matchTimer->isActive()) {
        matchTimer->start(1000);  // Ensure the timer is active
    }
}





void Simulation::endMatch() {
    matchTime--;
    ui->chrono->display(matchTime);
    if (matchTime <= 0) {
        matchTimer->stop();
        timer->stop();
        isGameRunning = false;
        resetPlayers();
        qDebug() << "Match ended!";
    }
}

void Simulation::resetPlayers() {
    for (auto it = initialPositions.begin(); it != initialPositions.end(); ++it) {
        it.key()->move(it.value());
    }
    goalProcessed = false;
}
