#include "receiver.h"

Receiver::Receiver(int x, int y, Orders* o) : MapBlock(RECEIVER, x, y), o(o)
{

}

void Receiver::receive(const std::vector<Food>& v)
{
    o->receive(Dish(v));
}

