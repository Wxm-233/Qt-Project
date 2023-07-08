#include "plate.h"
#include <pot.h>
#include <plate.h>
#include <game.h>

Plate::Plate(int x, int y, QWidget* parent) : Item(PLATE, x, y, parent)
{
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*GamePics::Plate));
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);
}

void Plate::addFood(Item*& f)
{
    if (f == nullptr || f->type != FOOD || foods.size() > 4)
        return;
    foods.push_back((Food*)f);
    f = nullptr;
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
        this->addFood(rAnother);
        break;
    case POT:
        if (((Pot*)rAnother)->isCooking())
            break;
        this->addFood(((Pot*)rAnother)->food());
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
