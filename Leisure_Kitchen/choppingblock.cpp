#include "choppingblock.h"

ChoppingBlock::ChoppingBlock(int x, int y, QWidget* parent) : MapBlock(CHOPPING_BLOCK, x, y, parent)
{
	t = new QTimer;
}

void ChoppingBlock::interact(Item*& i)
{
	if (i == nullptr) {
		i = f;
		f = nullptr;
	}
	else if (f == nullptr) {
		if (i->type == FOOD) {
			this->putFood((Food*)i);
			i = nullptr;
		}
	}
	else {
		i->interact(i, f);
	}
		
	
}

void ChoppingBlock::putFood(Food* food)
{
	f = food;
}