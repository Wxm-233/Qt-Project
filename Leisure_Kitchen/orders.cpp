#include "orders.h"

Orders::Orders(QWidget* father, ScoreBoard* sb) : father(father), sb(sb)
{
    t = new QTimer(this);
    t->start(25000);
    connect(t, &QTimer::timeout, this, &Orders::add);
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
            sb->addScore(i->value());
            orders.erase(i);
            break;
        }
    }
}
