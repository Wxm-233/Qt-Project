#ifndef COOKINGBENCH_H
#define COOKINGBENCH_H

#include <mapblock.h>
#include <QTimer>
#include <item.h>
#include <food.h>

class CookingBench : public MapBlock
{
public:
    CookingBench(int x, int y);
    bool putItem(Item* i);
    void processFood();
private:
    Item* i;
    QTimer* t;
};

//singleShot

#endif // COOKINGBENCH_H
