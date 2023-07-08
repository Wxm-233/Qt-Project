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
    movie = new QMovie(":/Pictures/assets/Pictures/Processing.gif");
}

void Pot::addFood(Item*& f)
{
    if (this->f != nullptr || f == nullptr || f->type != FOOD)
        return;
    if (((Food*)f)->isCooked())
        return;
    this->f = (Food*)f;
    f->hide();
    t->singleShot(ProcessingTime, this, &Pot::cookFood);
    t->start();
    processing = new QLabel(picture);
    processing->setGeometry(0, 0, PixelsPerBlock, PixelsPerBlock);
    processing->setMovie(movie);
    movie->start();
    processing->show();
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
    movie->stop();
    delete processing;
}

bool Pot::isCooking()
{
    return _isCooking;
}
