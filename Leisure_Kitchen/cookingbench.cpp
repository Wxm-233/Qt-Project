#include "cookingbench.h"

CookingBench::CookingBench(int x, int y) : MapBlock(COOKING_BENCH, x, y), i(nullptr)
{
    t = new QTimer();
}

bool CookingBench::putItem(Item *i)
{
    if (this->i != nullptr)
        return false;
    if (i->type != FOOD)
        return false;
    if (((Food*)i)->isProcessed())
        return false;

    this->i = i;
    t->singleShot(10000, this, &CookingBench::processFood);
    t->start();
    return true;
}

void CookingBench::processFood()
{
    ((Food*)i)->process();
}
