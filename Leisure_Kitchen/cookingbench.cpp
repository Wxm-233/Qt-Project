#include "cookingbench.h"
#include <game.h>

CookingBench::CookingBench(int x, int y, QWidget* parent) : MapBlock(COOKING_BENCH, x, y, parent), p(nullptr)
{
    t = new QTimer();
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*GamePics::CookingBench));
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);
    //std::clog<<"CookingBench was constructed"<<std::endl;
}

void CookingBench::interact(Item*& i)
{
    if (i == nullptr) {
        i = p;
        p = nullptr;
    }
    else if (p == nullptr) {
        if (i->type == POT) {
            p = i;
            i = nullptr;
        }
    }
    else {
        i->interact(i, p);
    }
}

//bool CookingBench::putItem(Item *i)
//{
//    if (this->i != nullptr)
//        return false;
//    if (i->type != FOOD)
//        return false;
//    if (((Food*)i)->isProcessed())
//        return false;

//    this->i = i;
//    t->singleShot(10000, this, &CookingBench::processFood);
//    t->start();
//    return true;
//}

//void CookingBench::processFood()
//{
//    ((Food*)i)->process();
//}
