
#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

#include <character.h>
#include <enums.h>
#include <orders.h>
#include <map.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow

{
    Q_OBJECT

public:
    Game(QWidget *parent);
    ~Game();
    void init();
    //bool is_Paused();
public slots:
    void mainLoop();
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent* e);
    void cFacingChange(double newFacing);
private:
    Ui::Game *ui;
    Character* c;
    QTimer* t;
    Orders* o;
    Map* m;
    ScoreBoard* sb;
    bool isPaused = false;
    bool directionStatus[4] = {false};
signals:
    void gamePaused();
    void gameResumed();
    void gameClosed();
    void cFacingChanged(QString qs);
};

#endif // GAME_H
