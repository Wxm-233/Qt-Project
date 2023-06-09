#ifndef PLATE_H
#define PLATE_H

#include <vector>

#include "item.h"

class Food;

class Plate : public Item
{
public:
    Plate(int x, int y, QWidget* parent);
    void addFood(Item*& f);
    void interact(Item*& rThis, Item*& rAnother);
    void clear();
    void move(int x, int y);
    const std::vector<Food*>& dish();
private:
    std::vector<Food*> foods;
};

#endif // PLATE_H
