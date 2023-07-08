#include "repository.h"
#include <game.h>

Repository::Repository(FoodType t, int x, int y, QWidget* parent) : MapBlock(REPOSITORY, x, y, parent), t(t)
{
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*GamePics::Repository));
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);

    food = new QLabel(parent);
    food->setPixmap(QPixmap::fromImage(*fType2QImage(t)));
    food->resize(PixelsPerFood, PixelsPerFood);
    food->move(pos.first + (PixelsPerBlock - PixelsPerFood) / 2, pos.second + (PixelsPerBlock - PixelsPerFood) / 2 + 10);

}

FoodType Repository::type()
{
    return t;
}

void Repository::interact(Item*& i)
{
    if (i == nullptr) {
        //i = new Plate(x, y, parent);
        i = new Food(t, x, y, parent);
        i->show();
        //i = new Pot(x, y, parent);
    }
}
