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
    movie = new QMovie(":/Pictures/assets/Pictures/Processing.gif");
}

ChoppingBlock::~ChoppingBlock()
{
    delete movie;
}


void ChoppingBlock::interact(Item*& i)
{
    if (i == nullptr && !_isCutting) {
		i = f;
		f = nullptr;
	}
	else if (f == nullptr) {
		if (i->type == FOOD) {
            this->putFood(i);
		}
	}
	else {
        if (!_isCutting)
            i->interact(i, f);
	}
		
	
}

void ChoppingBlock::putFood(Item*& food)
{
    if (this->f != nullptr || food == nullptr || food->type != FOOD)
        return;
    if (((Food*)food)->isCut())
        return;
    this->f = (Food*)food;
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    f->move(pos.first + (PixelsPerBlock - PixelsPerFood) / 2, pos.second + (PixelsPerBlock - PixelsPerFood) / 2);
    t->singleShot(ProcessingTime, this, &ChoppingBlock::cutFood);
    t->start();
    processing = new QLabel(picture);
    processing->setGeometry(0, 0, PixelsPerBlock, PixelsPerBlock);
    processing->setMovie(movie);
    movie->start();
    processing->show();
    _isCutting = true;
    food = nullptr;
}

Item*& ChoppingBlock::food()
{
    return f;
}

void ChoppingBlock::cutFood()
{
    if (f == nullptr || f->type != FOOD)
        return;
    ((Food*)f)->cut();
    _isCutting = false;
    movie->stop();
    delete processing;
}

bool ChoppingBlock::isCutting()
{
    return _isCutting;
}
