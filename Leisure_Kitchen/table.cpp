#include "table.h"

Table::Table(Item* i, int x, int y, QWidget* parent) : i(i), MapBlock(TABLE, x, y, parent)
{

}

void Table::interact(Item*& i)
{
	if (i == nullptr) {
		i = this->i;
		this->i = nullptr;
	}
	else if (this->i == nullptr) {
		this->i = i;
		i = nullptr;
	}
	else {
		i->interact(i, this->i);
	}
}

//Item* Table::pick_up()
//{
//    Item* tmp = i;
//    i = nullptr;
//    return tmp;
//}
//
//bool Table::put_down(Item *i)
//{
//    if (i != nullptr)
//        return false;
//    this->i = i;
//    return true;
//}
//
//bool Table::isEmpty()
//{
//    return i == nullptr;
//}
//
//Item* Table::getItem()
//{
//    return i;
//}
