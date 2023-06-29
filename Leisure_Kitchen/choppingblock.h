#ifndef CHOPPINGBLOCK_H
#define CHOPPINGBLOCK_H

#include "mapblock.h"
#include <food.h>

class ChoppingBlock : public MapBlock
{
public:
    ChoppingBlock(int x, int y);
    bool put_food(Food *f);
private:
    QTimer* t;
    Food* f;
};

#endif // CHOPPINGBLOCK_H
