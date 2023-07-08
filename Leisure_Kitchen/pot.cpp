#include "pot.h"
#include <plate.h>
#include <food.h>
#include <game.h>

Pot::Pot(int x, int y, QWidget* parent) : Item(POT, x, y, parent)
{
    t = new QTimer;
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*GamePics::Pot));
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);
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
