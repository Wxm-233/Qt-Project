#include "item.h"

Item::Item(ItemType type, int x, int y, QWidget* parent) : type(type), x(x), y(y), parent(parent)
{
    picture = new QLabel;
}

Item::~Item()
{
    delete picture;
}

void Item::move(int x, int y)
{
    picture->move(x, y);
}
