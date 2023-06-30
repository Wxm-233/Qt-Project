#ifndef ORDERS_H
#define ORDERS_H
#include <vector>
#include <QTimer>
#include <dish.h>
#include <random>
#include <QWidget>
#include <QMainWindow>
#include <scoreboard.h>

namespace Ui {
class Order;
}

class Orders : public QObject
{
public:
    Orders(QWidget *father, ScoreBoard* sb);
    void add();
    void pause();
    void resume();
    void receive(const Dish& d);
private:
    std::vector<Dish> orders;
    QTimer* t;
    std::vector<Dish> available_dishes;
    QWidget* father;
    ScoreBoard* sb;
};

#endif // ORDERS_H
