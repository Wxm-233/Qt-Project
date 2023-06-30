#include "choppingblock.h"

ChoppingBlock::ChoppingBlock(int x, int y, QWidget* parent) : MapBlock(CHOPPING_BLOCK, x, y, parent)
{

}

bool ChoppingBlock::put_food(Food *f)
{
    return true;
}
