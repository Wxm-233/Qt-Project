#ifndef POT_H
#define POT_H

#include <QTimer>

#include "item.h"
#include <food.h>

class Pot : public Item
{
public:
    Pot(int x, int y);
    void interact(Item*& rThis, Item*& rAnother);
    void addFood(Item*& f);
    bool isCooking();
    Item*& food();
private:
    QTimer* t;
    Item* f = nullptr;
    bool _isCooking = false;
public slots:
    void cookFood();
};

#endif // POT_H

//
