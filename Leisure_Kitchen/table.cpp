#include "table.h"

Table::Table(Item* i, int x, int y) : i(i), MapBlock(TABLE, x, y)
{

}

Item* Table::pick_up()
{
    Item* tmp = i;
    i = nullptr;
    return tmp;
}

bool Table::put_down(Item *i)
{
    if (i != nullptr)
        return false;
    this->i = i;
    return true;
}

bool Table::isEmpty()
{
    return i == nullptr;
}

Item* Table::getItem()
{
    return i;
}
