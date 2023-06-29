#include "pot.h"

Pot::Pot(int x, int y) : Item(POT, x, y)
{

}

bool Pot::put_food(Item *i)
{
    return true;
}
