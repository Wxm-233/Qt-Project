
#include "game.h"
#include "ui_game.h"


Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
    , start_window(parent)
{
    ui->setupUi(this);
    t = new QTimer(this);
    connect(t, &QTimer::timeout, this, &Game::mainLoop);
    t->start(1000 / FPS);

}

Game::~Game()
{
    delete t;
    delete ui;
}

void Game::keyPressEvent(QKeyEvent *e)
{
    if (e->isAutoRepeat())
        return;

    switch (e->key()) {
    case Qt::Key_Escape:
        pause();
        break;
    case Qt::Key_W:
        directionStatus[UP] = true;
        break;
    case Qt::Key_S:
        directionStatus[DOWN] = true;
        break;
    case Qt::Key_A:
        directionStatus[LEFT] = true;
        break;
    case Qt::Key_D:
        directionStatus[RIGHT] = true;
        break;
    case Qt::Key_I:
        c->dash();
        break;
    default:
        break;
    }
}

void Game::keyReleaseEvent(QKeyEvent *e)
{
    if (e->isAutoRepeat())
        return;

    switch (e->key()) {
    case Qt::Key_W:
        directionStatus[UP] = false;
        break;
    case Qt::Key_S:
        directionStatus[DOWN] = false;
        break;
    case Qt::Key_A:
        directionStatus[LEFT] = false;
        break;
    case Qt::Key_D:
        directionStatus[RIGHT] = false;
        break;
    default:
        break;
    }
}

void Game::mainLoop()
{
    if (isPaused)
        return;

    c->move(directionStatus);
}

void Game::pause()
{
    isPaused = true;
    QMessageBox::information(this, "PAUSED", "The game is paused.", QMessageBox::Ok);
    isPaused = false;
}

void Game::closeEvent(QCloseEvent *e)
{
    start_window->show();
}

void Game::init()
{
    int x = this->width() / 2;
    int y = this->height() * 5 / 8;
    c = new Character(this, x, y);
}

bool Game::is_Paused()
{
    return isPaused;
}
