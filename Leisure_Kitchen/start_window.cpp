#include "start_window.h"
#include "ui_start_window.h"

Start_Window::Start_Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start_Window)
{
    ui->setupUi(this);
    game = nullptr;
}

Start_Window::~Start_Window()
{
    delete ui;
}

void Start_Window::on_pushButton_clicked()
{
    game = new Game(this);
    game->setFixedSize(1600, 900);
    game->init();
    this->hide();
    game->show();
}

