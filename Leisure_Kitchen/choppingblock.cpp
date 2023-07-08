#include "choppingblock.h"
#include <game.h>

ChoppingBlock::ChoppingBlock(int x, int y, QWidget* parent) : MapBlock(CHOPPING_BLOCK, x, y, parent)
{
	t = new QTimer;
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*GamePics::ChoppingBlock));
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);
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
