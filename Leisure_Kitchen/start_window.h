#ifndef START_WINDOW_H
#define START_WINDOW_H

#include <QWidget>

#include <game.h>

namespace Ui {
class Start_Window;
}

class Start_Window : public QWidget
{
    Q_OBJECT

public:
    Start_Window(QWidget *parent = nullptr);
    ~Start_Window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Start_Window *ui;
    Game* game;
};

#endif // START_WINDOW_H
