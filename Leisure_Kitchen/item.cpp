#include "item.h"

Item::Item(ItemType type, int x, int y) : type(type), x(x), y(y)
{
	label = new QLabel;
}

Item::~Item()
{
	delete label;
}

void Item::move(int x, int y)
{
	label->move(x, y);
}