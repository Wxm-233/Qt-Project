#include "plate.h"
#include <pot.h>
#include <plate.h>

Plate::Plate(int x, int y) : Item(PLATE, x, y)
{

}

bool Plate::addFood(Food *f)
{
    if (foods.size() > 4)
        return false;
    else foods.push_back(f);
    return true;
}

void Plate::clear()
{
    for (auto i : foods)
        delete i;
    foods.clear();
}

void Plate::interact(Item*& rThis, Item*& rAnother)
{
    switch (rAnother->type) {
    case FOOD:
        this->addFood((Food*)rAnother);
        rAnother = nullptr;
        break;
    case POT:
        if (((Pot*)rAnother)->isCooking() || ((Pot*)rAnother)->food() == nullptr)
            break;
        if (this->addFood(((Pot*)rAnother)->food()))
            ((Pot*)rAnother)->food() = nullptr;
        break;
    case PLATE:
        break;
    default:
        break;
    }
}

const std::vector<Food*>& Plate::dish()
{
    return foods;
}