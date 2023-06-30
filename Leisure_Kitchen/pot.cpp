#include "pot.h"
#include <plate.h>
#include <food.h>

Pot::Pot(int x, int y) : Item(POT, x, y)
{

}

bool Pot::addFood(Food *f)
{
    return true;
}

Food*& Pot::food()
{
    return f;
}

void Pot::interact(Item*& rThis, Item*& rAnother)
{
    switch (rAnother->type) {
    case FOOD:
        if (this->f != nullptr)
            break;
        this->addFood((Food*)rAnother);
        rAnother = nullptr;
        break;
    case PLATE:
        if (this->f == nullptr || this->isCooking())
            break;
        ((Plate*)rAnother)->addFood(this->f);
        this->f = nullptr;
        break;
    case POT:
        break;
    default:
        break;
    }
}

void Pot::cookFood()
{

}

bool Pot::isCooking()
{
    return false;
}