#include "simulation.h"
#include "ui_dialog.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QSoundEffect>
#include <QMessageBox>


Simulation::Simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    isPaused(false),
    isGameRunning(false),
    blueScore(0),
    redScore(0),
    goalProcessed(false),
    isBlueTurn(true), // Blue team starts first
    matchTime(15),// 15 seconds match time
    matchEnded(false)


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
    if (!isGameRunning && matchTime > 0) {  // Only allow start if time remains
        timer->start(100);
        matchTimer->start(1000);
        isGameRunning = true;
        isPaused = false;
        qDebug() << "Game starting!";
    }
}
void Simulation::updateMatchTime() {
    if (matchTime > 0) {
        matchTime--;
        ui->chrono->display(matchTime);
    }

    if (matchTime == 0) {
        matchTimer->stop();
        timer->stop();
        isGameRunning = false;

        if (currentHalf == 1) {
            currentHalf = 2;
            matchTime = 15;
            ui->chrono->display(matchTime);
            resetGame();
            QTimer::singleShot(2000, [this]() {
                qDebug() << "Starting second half!";
                timer->start(100);
                matchTimer->start(1000);
                isGameRunning = true;
            });
        } else {
            qDebug() << "Second half ended!";
            if (blueScore == redScore) {
                isTieBreaker = true;
                startPenalties();
            } else {
                showFinalResult();
                // Disable further gameplay
                isGameRunning = false;
                matchEnded = true;
            }
        }
    }
    }

void Simulation::startPenalties() {
    qDebug() << "Starting penalty shootout!";
    bluePenGoals = 0;
    redPenGoals = 0;
    totalPenaltiesTaken = 0;
    isBluePenaltyTurn = true;

    // Set displayed score to 0-0 for the shootout
    ui->scoreb->setText("0");
    ui->scorer->setText("0");

    setupPenalty(true); // Start with blue
}



void Simulation::setupPenalty(bool isBlueTurn) {
    if (isBlueTurn) {
        currentPenaltyShooter = ui->Player10;
        currentPenaltyTarget = ui->GOAL;

        ui->Ball->move(ui->penalty->pos());

        // Shooter stands to the left of the ball
        int shooterX = ui->penalty->x() - currentPenaltyShooter->width() - 10;
        int shooterY = ui->penalty->y();
        currentPenaltyShooter->move(shooterX, shooterY);
    } else {
        currentPenaltyShooter = ui->Player15;
        currentPenaltyTarget = ui->GOAL1;

        ui->Ball->move(ui->penalty1->pos());

        // ✅ Shooter stands in front of the ball (further away from goal)
        int shooterX = ui->penalty1->x() + ui->Ball->width() + 10;
        int shooterY = ui->penalty1->y();
        currentPenaltyShooter->move(shooterX, shooterY);
    }

    // Goalkeeper placement
    QLabel* keeper = isBlueTurn ? ui->Player22 : ui->Player1;
    QLabel* keeperPos = isBlueTurn ? ui->keeper : ui->keeper1;
    keeper->move(keeperPos->pos());

    // Delay, then kick
    QTimer::singleShot(1000, [this, isBlueTurn]() {
        kickBall(isBlueTurn);
    });
}


void Simulation::kickBall(bool isBlueTurn) {
    currentPenaltyShooter->move(ui->Ball->x() - 20, ui->Ball->y());

    QTimer::singleShot(400, [this, isBlueTurn]() {
        bool isGoal = QRandomGenerator::global()->bounded(100) < 60;

        if (isGoal) {
            ui->Ball->move(currentPenaltyTarget->pos());
            if (isBlueTurn) {
                bluePenGoals++;
                ui->scoreb->setText(QString::number(blueScore + bluePenGoals));
            } else {
                redPenGoals++;
                ui->scorer->setText(QString::number(redScore + redPenGoals));
            }
            qDebug() << (isBlueTurn ? "Blue" : "Red") << "scores!";
        } else {
            int missX = currentPenaltyTarget->x() + QRandomGenerator::global()->bounded(-50, 50);
            int missY = currentPenaltyTarget->y() + QRandomGenerator::global()->bounded(20, 100);
            ui->Ball->move(missX, missY);
            qDebug() << (isBlueTurn ? "Blue" : "Red") << "misses!";
        }

        // Count penalties
        if (isBlueTurn) bluePenaltiesTaken++;
        else redPenaltiesTaken++;

        // Continue if both teams have taken fewer than 3
        QTimer::singleShot(2000, [this]() {
            if (bluePenaltiesTaken < 3 || redPenaltiesTaken < 3) {
                // Alternate turns
                isBluePenaltyTurn = !isBluePenaltyTurn;
                setupPenalty(isBluePenaltyTurn);
            } else {
                showFinalResult();
            }
        });
    });
}





void Simulation::takePenalty(bool isBlueTurn) {
    bool isGoal = QRandomGenerator::global()->bounded(100) < 60;

    if (isGoal) {
        ui->Ball->move(currentPenaltyTarget->pos());

        if (isBlueTurn) {
            bluePenGoals++;
            ui->scoreb->setText(QString::number(bluePenGoals));  // Penalty score
        } else {
            redPenGoals++;
            ui->scorer->setText(QString::number(redPenGoals));
        }
        qDebug() << (isBlueTurn ? "Blue" : "Red") << "team scores penalty!";
    }


    if (isBlueTurn) bluePenaltiesTaken++;
    else redPenaltiesTaken++;

    QTimer::singleShot(2000, [this]() {
        checkPenaltyShootoutState();
    });
}

void Simulation::checkPenaltyShootoutState() {
    int remainingBlue = 5 - bluePenaltiesTaken;
    int remainingRed = 5 - redPenaltiesTaken;

    // Before sudden death: stop if one team can't catch up
    if (!inSuddenDeath) {
        if ((bluePenGoals > redPenGoals + remainingRed) ||
            (redPenGoals > bluePenGoals + remainingBlue) ||
            (bluePenaltiesTaken == 5 && redPenaltiesTaken == 5)) {

            if (bluePenGoals == redPenGoals) {
                inSuddenDeath = true;
                qDebug() << "Entering Sudden Death!";
            } else {
                showPenaltyResult(); // Ends it
                return;
            }
        }
    } else {
        // Sudden death logic
        if (bluePenaltiesTaken > 5 && redPenaltiesTaken > 5) {
            if (bluePenGoals != redPenGoals) {
                showPenaltyResult();
                return;
            }
        }
    }

    // Continue to next penalty
    isBluePenaltyTurn = !isBluePenaltyTurn;
    setupPenalty(isBluePenaltyTurn);
}



void Simulation::showFinalResult() {
    QString winner;

    if (bluePenGoals > redPenGoals) {
        winner = "Blue team wins!";
    } else if(redPenGoals > bluePenGoals) {
        winner = "Red team wins!";
    }

    qDebug() << winner;
    QMessageBox::information(nullptr, "Penalty Result", winner);

    resetGame();
}


void Simulation::showPenaltyResult() {
    isPenaltyShootout = false;
    QString result;

    if (bluePenGoals > redPenGoals)
        result = "Blue team wins on penalties!";
    else if (redPenGoals > bluePenGoals)
        result = "Red team wins on penalties!";
    else
        result = "Match ends in a draw!"; // only happens in rare cases

    qDebug() << result;
    QMessageBox::information(nullptr, "Penalty Result", result);

    resetGame();
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
        moveDefenders(12, 21, ui->Ball); // 👈 This will handle Player12 to Player22
          // Red team defends
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
    int speed = 5;  // You can tweak this value for faster/slower defenders

    for (int i = start; i <= end; ++i) {
        QLabel *defender = findChild<QLabel*>(QString("Player%1").arg(i));
        if (!defender) {
            qDebug() << "Missing label: Player" << i;
            continue;
        }

        int dx = target->x() - defender->x();
        int dy = target->y() - defender->y();
        int distance = std::sqrt(dx * dx + dy * dy);

        // If already at the target, skip movement
        if (distance == 0)
            continue;

        // Normalize direction and apply speed
        int moveX = (dx * speed) / distance;
        int moveY = (dy * speed) / distance;

        // New position
        int newX = defender->x() + moveX;
        int newY = defender->y() + moveY;

        // Move the defender
        defender->move(newX, newY);

        // Debug output
        qDebug() << defender->objectName() << "moved to:" << newX << newY << "Δ:" << moveX << moveY;
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
    QLabel *ball = ui->Ball;
    QLabel *keeper = isBlueTurn ? ui->Player22 : ui->Player1;
    QLabel *savePosition = isBlueTurn ? ui->keeper : ui->keeper1;

    // Chance of keeper saving (40%)
    bool keeperSaves = QRandomGenerator::global()->bounded(100) < 40;

    // Chance to miss (25%)
    bool isMiss = QRandomGenerator::global()->bounded(4) == 0;

    if (keeperSaves) {
        // Keeper moves to save position, ball moves far from goal
        keeper->move(savePosition->pos());
        ball->move(savePosition->x() + 50, savePosition->y());  // ✅ Move ball clearly outside goal
        qDebug() << "Keeper saved!";
        goalProcessed = true;  // ✅ Block goal detection
        QTimer::singleShot(500, this, &Simulation::switchTurn);
        return;
    }

    if (isMiss) {
        int missOffsetX = QRandomGenerator::global()->bounded(-60, 60);
        int missOffsetY = QRandomGenerator::global()->bounded(-30, 30);
        ball->move(goal->x() + missOffsetX, goal->y() + missOffsetY);
        qDebug() << "Shot missed!";
        goalProcessed = true;  // ✅ Block goal detection
        QTimer::singleShot(500, this, &Simulation::switchTurn);
        return;
    }

    // Only this case is on target
    ball->move(goal->x(), goal->y());
    qDebug() << "Shot on target!";
    checkGoalScored();  // ✅ Only called for valid shots
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
        qDebug() << "Goal scored by" << (isBlueTurn ? "Blue" : "Red") << "!";
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
    resetGame();  // Reset player positions

    goalProcessed = false;  // ✅ Reset goal status here

    QTimer::singleShot(1000, this, [this]() {
        isBlueTurn = !isBlueTurn;  // Switch turn
        isGameRunning = true;
        isPaused = false;
        timer->start(100);
        qDebug() << "Switching turn to" << (isBlueTurn ? "Blue" : "Red") << "team!";
    });

    if (!matchTimer->isActive()) {
        matchTimer->start(1000);
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
