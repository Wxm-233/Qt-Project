#ifndef POT_H
#define POT_H

#include "item.h"
#include <food.h>

class Pot : public Item
{
public:
    Pot(int x, int y);
    void clear();
    bool put_food(Item* i);
    Food* pour_food();
    Food* ladle_out_food();
private:
    QTimer* t;
    Food* f;

};

#endif // POT_H

//
