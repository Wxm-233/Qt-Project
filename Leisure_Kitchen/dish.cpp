#include "dish.h"

Dish::Dish(const std::vector<Food>& f, int value) : _value(value)
{
    for (auto &i : f)
    {
        this->foods.insert(i);
    }
}

bool Dish::operator==(const Dish& another) const
{
    return this->foods == another.foods;
}

int Dish::value()
{
    return _value;
}
