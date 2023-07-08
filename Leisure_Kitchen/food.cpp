#include "food.h"
#include <pot.h>
#include <plate.h>
#include <game.h>

Food::Food(FoodType t, int x, int y, QWidget* parent) : Item(FOOD, x, y, parent), t(t)
{
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*fType2QImage(t)));

    switch (t)
    {
    case FISH:
        _isCut = false;
        _isCooked = true;
        break;
    case RICE:
        _isCut = true;
        _isCooked = false;
        break;
    case HAITAI:
        _isCut = true;
        _isCooked = true;
        break;
    case CUCUMBER:
        _isCut = false;
        _isCooked = true;
        break;
    case CABBAGE:
        _isCut = false;
        _isCooked = true;
        break;
    case TOMATO:
        _isCut = false;
        _isCooked = true;
        break;
    default:
        break;
    }
    picture->resize(PixelsPerFood,PixelsPerFood);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);
    picture->raise();
}

void Food::interact(Item*& rThis, Item*& rAnother)
{
    switch (rAnother->type) {
    case FOOD:
        break;
    case POT:
        ((Pot*)rAnother)->addFood(rThis);
        break;
    case PLATE:
        ((Plate*)rAnother)->addFood(rThis);
        break;
    default:
        break;
    }
}

bool Food::operator< (const Food& another) const
{
    return this->t != another.t ? this->t < another.t : this->_isCut != another._isCut ? this->_isCut < another._isCut : this->_isCooked < another._isCooked;
}

bool Food::operator== (const Food& another) const
{
    return this->t == another.t && this->_isCut == another._isCut && this->_isCooked == another._isCooked;
}

FoodType Food::type()
{
    return t;
}

bool Food::isProcessed()
{
    return _isCooked && _isCut;
}

bool Food::isCut()
{
    return _isCut;
}

bool Food::isCooked()
{
    return _isCooked;
}

void Food::cut()
{
    _isCut = true;
    switch (t) {
    case FISH:
        picture->setPixmap(QPixmap::fromImage(*GamePics::Fish_Cut));
        break;
    case CABBAGE:
        picture->setPixmap(QPixmap::fromImage(*GamePics::Cabbage_Cut));
        break;
    case CUCUMBER:
        picture->setPixmap(QPixmap::fromImage(*GamePics::Cucumber_Cut));
        break;
    case TOMATO:
        picture->setPixmap(QPixmap::fromImage(*GamePics::Tomato_Cut));
        break;
    default:
        break;
    }
}

void Food::cook()
{
    switch (t) {
    case RICE:
        picture->setPixmap(QPixmap::fromImage(*GamePics::Rice_Cooked));
        break;
    default:
        break;
    }
    _isCooked = true;
}
