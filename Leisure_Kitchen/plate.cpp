#include "plate.h"

Plate::Plate(int x, int y) : Item(PLATE, x, y)
{

}

bool Plate::add_food(Item *i)
{
    return true;
}
