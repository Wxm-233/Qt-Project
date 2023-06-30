#include "trashcan.h"

TrashCan::TrashCan(int x, int y, QWidget* parent) : MapBlock(TRASH_CAN, x, y, parent)
{

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
