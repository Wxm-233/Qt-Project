#include "receiver.h"

Receiver::Receiver(int x, int y, Orders* o, QWidget* parent) : MapBlock(RECEIVER, x, y, parent), o(o)
{

}

void Receiver::receive(const std::vector<Food*>& v)
{
    o->receive(Dish(v));
}

void Receiver::interact(Item*& i)
{
    if (i != nullptr && i->type == PLATE) {
        this->receive(((Plate*)i)->dish());
    }
    ((Plate*)(i))->clear();
}