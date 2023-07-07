
#include "game.h"
#include "ui_game.h"


Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);

    int cx = this->width() / 2;
    int cy = this->height() * 5 / 8;
    c = new Character(this, cx, cy);

    t = new QTimer(this);
    QObject::connect(t, &QTimer::timeout, this, &Game::mainLoop);
    t->start(1000 / FPS);

    o = new Orders(this);
    sb = new ScoreBoard(this);
    m = new Map(this);
    m->init();
    //connect(c, &Character::facing_changed, this, &Game::cFacingChange);
}

Game::~Game()
{
    delete ui;
    delete c;
    delete t;
    delete sb;
    delete m;
}

void Game::keyPressEvent(QKeyEvent *e)
{
    if (e->isAutoRepeat())
        return;

    switch (e->key()) {
    case Qt::Key_Space:
        if (isPaused)
            emit gamePaused();
        else {
            for (auto& i : directionStatus)
                i = false;
            emit gameResumed();
        }
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
        c->dash(m);
        break;
    case Qt::Key_U:
        c->interact(m);
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

void Game::closeEvent(QCloseEvent *e)
{
    emit gameClosed();
    this->deleteLater();
}

//void Game::cFacingChange(double newFacing)
//{
//    ui->Facing->setText(QString("Facing:%1").arg(newFacing));
//    //emit cFacingChanged(QString::fromStdString("newFacing" + std::to_string(newFacing)));
//}

void Game::mainLoop()
{
    if (isPaused)
        return;
    c->move(directionStatus, m);
}

void Game::init()//connect signals with slots
{
    connect(o, &Orders::addScore, sb, &ScoreBoard::addScore);
    connect(m, &Map::receiveDish, o, &Orders::receive);
}
