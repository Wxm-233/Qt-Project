
#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <character.h>
#include <enums.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow

{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();
    void mainLoop();
    void pause();
    void init();
    bool is_Paused();
protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
private slots:

private:
    Ui::Game *ui;
    Character* c;
    QWidget* start_window;
    QTimer* t;
    void closeEvent(QCloseEvent* e);
    bool isPaused = false;
    bool directionStatus[4] = {false};
};

#endif // GAME_H
