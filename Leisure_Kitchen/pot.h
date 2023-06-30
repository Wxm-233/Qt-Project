#ifndef POT_H
#define POT_H

#include "item.h"
#include <food.h>

class Pot : public Item
{
public:
    Pot(int x, int y);
    void interact(Item*& rThis, Item*& rAnother);
    bool addFood(Food* f);
    void cookFood();
    bool isCooking();
    Food*& food();
private:
    QTimer* t;
    Food* f = nullptr;

};

#endif // POT_H

//
