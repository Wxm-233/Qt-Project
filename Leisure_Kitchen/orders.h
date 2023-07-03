#ifndef ORDERS_H
#define ORDERS_H


#include <QTimer>
#include <QWidget>
#include <QMainWindow>

#include <vector>
#include <random>

#include <dish.h>


class Orders : public QObject
{
    Q_OBJECT

public:
    Orders(QWidget *father);
    void add();
    
private:
    std::vector<Dish> orders;
    QTimer* t;
    std::vector<Dish> available_dishes;
    QWidget* father;
public slots:
    void pause();
    void resume();
    void receive(const Dish& d);
signals:
    void addScore(int value);
};

#endif // ORDERS_H
