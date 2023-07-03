#include "receiver.h"
#include <map.h>

Receiver::Receiver(int x, int y, Map* m, QWidget* parent) : MapBlock(RECEIVER, x, y, parent)
{

}

void Receiver::receive(const std::vector<Food*>& v)
{
    //m->receive(Dish(v));
}

void Receiver::interact(Item*& i)
{
    if (i != nullptr && i->type == PLATE) {
        this->receive(((Plate*)i)->dish());
    }
    ((Plate*)(i))->clear();
}
