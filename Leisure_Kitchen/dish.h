#ifndef DISH_H
#define DISH_H

#include <set>
#include <food.h>

class Dish
{
public:
    Dish(const std::vector<Food*>& f, int value = 0);
    bool operator==(const Dish& another) const;
    int value();
private:
    std::multiset<Food*> foods;
    int _value;
};

#endif // DISH_H
