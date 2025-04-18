#ifndef SIMULATION_H
#define SIMULATION_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDialog>
#include <QTimer>
#include <QLabel>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "arduino.h"
namespace Ui {
class Dialog;
}

class Simulation : public QDialog
{
    Q_OBJECT

public:
    explicit Simulation(Arduino* a, QWidget *parent = nullptr);
    ~Simulation();

private slots:
    void on_Start_clicked();
    void on_Resume_clicked();
    void on_Pause_clicked();
    void updatePositions();
    void on_pens_clicked();

private:
    Ui::Dialog *ui;
    QPushButton *Start;
    QSerialPort *serialPort;
    Arduino *arduino;  // Already done? Just make sure it's initialized to nullptr
    QTimer *timer;
    bool isPaused;
    bool isGameRunning;
    int blueScore;
    int redScore;
    bool goalProcessed;
    bool isBlueTurn;  // Flag to track which team is attacking
    QMap<QLabel*, QPoint> initialPositions;
    QTimer *matchTimer;  // Declare match timer
    int matchTime;
    int currentHalf = 1; // 1 or 2
    bool isTieBreaker = false; // true if going to penalties
    int penaltyRound = 0;
    int bluePenGoals = 0;
    int redPenGoals = 0;
    bool isBluePenaltyTurn = true;
    bool gameInterrupted = false;
    bool isPenaltyShootout;
    QLabel* currentPenaltyShooter;
    QLabel* currentPenaltyTarget;
    bool matchEnded;
    int totalPenaltiesTaken = 0;
    const int maxPenalties = 5; // can be increased later
    int bluePenaltiesTaken = 0;
    int redPenaltiesTaken = 0;
    bool inSuddenDeath = false;
    int savedBlueScore = blueScore;
    int savedRedScore = redScore;
    bool isMatchStarted = false;







    // Updated function signatures with parameters
    void paintEvent(QPaintEvent *event);
    void movePlayersTowardsBall(int start, int end);
    void moveAttackers(int start, int end, QLabel *goal);
    void moveDefenders(int start, int end, QLabel *target);
    bool checkInterception(int defenderStart, int defenderEnd);
    void interceptionHappened();
    void shootBall(QLabel *shooter, QLabel *goal);
    void moveDefendersTowardsBall(int start, int end);
    void checkInterception(); // no parameters now
    void checkGoalScored();
    void passBall(QLabel *player, int ballX, int ballY);
    void movePlayerTowardsGoal(QLabel *player);
    void updateMatchTime();
    void decideShotOutcome(QLabel *shooter);
    void missShot(QLabel *shooter);
    void initializePlayers();
    void moveRedAttackers();
    void moveBallTowards(int targetX, int targetY);
    void switchTurn();
    void saveInitialPositions();
    void resetGame();
    void endMatch();
    void resetPlayers();
    void startPenalties();
    void takePenalty(bool isBlueTurn);
    void showFinalResult();
    void showPenaltyResult();
    void setupPenalty(bool isBlueTurn);
    void kickBall(bool isBlueTurn);
    void checkPenaltyShootoutState();
    void hideMatchPlayersForPenalties();
    void initSerial();
    void updateLCD();
    void stopUpdating();

};

#endif // SIMULATION_H
