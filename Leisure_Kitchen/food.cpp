#include "food.h"
#include <pot.h>
#include <plate.h>
#include <game.h>

Food::Food(FoodType t, int x, int y, QWidget* parent) : Item(FOOD, x, y,parent),t(t)
{
    picture = new QLabel(parent);

    switch (t)
    {
    case FISH:
        _isCut = false;
        _isCooked = true;
        picture->setPixmap(QPixmap::fromImage(*GamePics::Fish));
        break;
    case RICE:
        _isCut = true;
        _isCooked = false;
        picture->setPixmap(QPixmap::fromImage(*GamePics::Rice_Raw));
        break;
    case HAITAI:
        _isCut = true;
        _isCooked = true;
        picture->setPixmap(QPixmap::fromImage(*GamePics::HaiTai));
        break;
    case CUCUMBER:
        _isCut = false;
        _isCooked = true;
        picture->setPixmap(QPixmap::fromImage(*GamePics::Cucumber));
        break;
    case CABBAGE:
        _isCut = false;
        _isCooked = true;
        picture->setPixmap(QPixmap::fromImage(*GamePics::Cabbage));
        break;
    case TOMATO:
        _isCut = false;
        _isCooked = true;
        picture->setPixmap(QPixmap::fromImage(*GamePics::Tomato));
        break;
    default:
        break;
    }
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);
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
}

void Food::cook()
{
    _isCooked = true;
}
