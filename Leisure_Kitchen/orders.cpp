#include "orders.h"

Orders::Orders(QWidget* father) : father(father)
{
    t = new QTimer(this);
    t->start(25000);
    connect(t, &QTimer::timeout, this, &Orders::add);
    Food f(HAITAI, 0, 0, father);
    available_dishes.push_back(Dish({new Food(HAITAI, 0, 0, father) }, 5));
}

void Orders::add()
{
    if (orders.size() > 6)
        return;
    orders.push_back(available_dishes[std::rand() % available_dishes.size()]);
}

void Orders::pause()
{
    t->stop();
}

void Orders::resume()
{
    t->start();
}

void Orders::receive(const Dish& d)
{
    for (auto i = orders.begin(); i != orders.end(); i++) {
        if (d == *i) {
            emit addScore(i->value());
            orders.erase(i);
            return;
        }
    }
}
