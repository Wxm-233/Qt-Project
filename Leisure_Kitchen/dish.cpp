#include "dish.h"

Dish::Dish(const std::vector<Food*>& f, int value) : _value(value)
{
    for (auto &i : f) {
        this->foods.insert(i);
    }
    for (auto& i : foods) {
        i->hide();
    }
}

bool Dish::operator==(const Dish& another) const
{
    if (this->foods.size() != another.foods.size())
        return false;
    auto it1 = this->foods.begin();
    auto it2 = another.foods.begin();
    while (it1 != this->foods.end()) {
        if (!(**it1 == **it2))
            return false;
        it1++, it2++;
    }
    return true;
}

int Dish::value()
{
    return _value;
}
