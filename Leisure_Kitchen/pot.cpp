#include "pot.h"
#include <plate.h>
#include <food.h>

Pot::Pot(int x, int y) : Item(POT, x, y)
{
    t = new QTimer;
}

void Pot::addFood(Item*& f)
{
    if (this->f != nullptr || f == nullptr || f->type != FOOD)
        return;
    if (((Food*)f)->isCooked())
        return;
    this->f = (Food*)f;
    t->singleShot(10000, this, &Pot::cookFood);
    t->start();
    _isCooking = true;
    f = nullptr;
}

Item*& Pot::food()
{
    return f;
}

void Pot::interact(Item*& rThis, Item*& rAnother)
{
    switch (rAnother->type) {
    case FOOD:
        this->addFood(rAnother);
        break;
    case PLATE:
        if (this->isCooking())
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
    if (f == nullptr || f->type != FOOD)
        return;
    ((Food*)f)->cook();
    _isCooking = false;
}

bool Pot::isCooking()
{
    return _isCooking;
}