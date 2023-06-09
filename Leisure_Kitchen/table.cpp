#include "table.h"
#include <game.h>

Table::Table(Item* i, int x, int y, QWidget* parent) : MapBlock(TABLE, x, y, parent), i(i)
{
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*GamePics::Table));
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);

    if (i == nullptr)
        return;
    i->move(pos.first + (PixelsPerBlock - PixelsPerItem) / 2, pos.second + (PixelsPerBlock - PixelsPerItem) / 2);
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
        if (this->i != nullptr) {
            auto pos = block2Pixel(this->x, this->y, (dynamic_cast<Game*>(parent))->m);
            this->i->move(pos.first + (PixelsPerBlock - PixelsPerItem) / 2, pos.second + (PixelsPerBlock - PixelsPerItem) / 2);
        }
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
