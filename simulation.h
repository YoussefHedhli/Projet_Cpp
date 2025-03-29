#ifndef SIMULATION_H
#define SIMULATION_H

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
    bool goalProcessed;
    QMap<QLabel*, QPoint> initialPositions;

    void movePlayersTowardsBall();
    void checkGoalScored();
    void passBall(QLabel *player, int ballX, int ballY);
    void movePlayerTowardsGoal(QLabel *player);
    void decideShotOutcome(QLabel *shooter);
    void missShot(QLabel *shooter);
    void shootBall(QLabel *player);
    void moveAttackers();
    void initializePlayers();
    void saveInitialPositions();
    void resetGame();
};

#endif // SIMULATION_H
