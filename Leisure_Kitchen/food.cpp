#include "food.h"

Food::Food(FoodType t, int x, int y) : t(t), Item(FOOD, x, y)
{

}

bool Food::operator< (const Food& another) const
{
    return this->t != another.t ? this->t < another.t : this->_isProcessed < another._isProcessed;
}

bool Food::operator== (const Food& another) const
{
    return this->t == another.t && this->_isProcessed == another._isProcessed;
}

FoodType Food::type()
{
    return t;
}

bool Food::isProcessed()
{
    return _isProcessed;
}

void Food::process()
{
    _isProcessed = true;
}
