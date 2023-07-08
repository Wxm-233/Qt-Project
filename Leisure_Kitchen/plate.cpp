#include "plate.h"
#include <pot.h>
#include <plate.h>
#include <game.h>

Plate::Plate(int x, int y, QWidget* parent) : Item(PLATE, x, y, parent)
{
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*GamePics::Plate));
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int, int> pos = block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);
}

void Plate::addFood(Item*& f)
{
    if (f == nullptr || f->type != FOOD || foods.size() > 3)
        return;
    foods.push_back((Food*)f);
    f->show();
    f = nullptr;
    this->move(x, y);
}

void Plate::clear()
{
    for (auto i : foods)
        delete i;
    foods.clear();
}

void Plate::move(int x, int y)
{
    this->Item::move(x, y);
    if (foods.size() < 1)
        return;
    foods[0]->move(x, y);
    if (foods.size() < 2)
        return;
    foods[1]->move(x+PixelsPerItem/2, y);
    if (foods.size() < 3)
        return;
    foods[2]->move(x, y+PixelsPerItem/2);
    if (foods.size() < 4)
        return;
    foods[3]->move(x+PixelsPerItem/2, y+PixelsPerItem/2);

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
