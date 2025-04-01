#ifndef SIMULATION_H
#define SIMULATION_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDialog>
#include <QTimer>
#include <QLabel>

namespace Ui {
class Dialog;
}

class Simulation : public QDialog
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = nullptr);
    ~Simulation();

private slots:
    void on_Start_clicked();
    void on_Resume_clicked();
    void on_Pause_clicked();
    void updatePositions();

private:
    Ui::Dialog *ui;
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
    QMediaPlayer *goalCheer;
    QMediaPlayer *whistleEnd;
    QMediaPlayer *fansCheering;
    QMediaPlayer *whistleStart;
    QAudioOutput *audioOutput;

    // Updated function signatures with parameters
    void paintEvent(QPaintEvent *event);
    void movePlayersTowardsBall(int start, int end);
    void moveAttackers(int start, int end, QLabel *goal);
    void shootBall(QLabel *shooter, QLabel *goal);

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
};

#endif // SIMULATION_H
