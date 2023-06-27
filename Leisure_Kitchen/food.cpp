#include "food.h"

Food::Food(FoodType t, int x, int y) : type(t), Item(FOOD, x, y)
{

}

bool Food::operator< (const Food& another) const
{
    return this->type != another.type ? this->type < another.type : this->isProcessed < another.isProcessed;
}

bool Food::operator== (const Food& another) const
{
    return this->type == another.type && this->isProcessed == another.isProcessed;
}
