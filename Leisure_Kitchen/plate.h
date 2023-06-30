#ifndef PLATE_H
#define PLATE_H

#include <vector>

#include "item.h"
#include <food.h>

class Plate : public Item
{
public:
    Plate(int x, int y);
    bool addFood(Food* f);
    void interact(Item*& rThis, Item*& rAnother);
    void clear();
    const std::vector<Food*>& dish();
private:
    std::vector<Food*> foods;
};

#endif // PLATE_H
