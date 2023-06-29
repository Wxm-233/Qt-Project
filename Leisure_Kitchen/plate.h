#ifndef PLATE_H
#define PLATE_H

#include "item.h"
#include <food.h>
#include <vector>

class Plate : public Item
{
public:
    Plate(int x, int y);
    bool add_food(Item* i);
    void clear();
private:
    std::vector<Food> foods;
};

#endif // PLATE_H
