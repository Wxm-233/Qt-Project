#include "trashcan.h"
#include <game.h>

TrashCan::TrashCan(int x, int y, QWidget* parent) : MapBlock(TRASH_CAN, x, y, parent)
{
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*GamePics::TrashCan));
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);
}

void TrashCan::interact(Item*& i)
{
	if (i->type == PLATE)
		((Plate*)i)->clear();
	else if (i->type == POT) {
		if (((Pot*)i)->food() != nullptr) {
			delete ((Pot*)i)->food();
			((Pot*)i)->food() = nullptr;
		}
	}
	else {
		delete i;
		i = nullptr;
	}
}
