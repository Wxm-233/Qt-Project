#include "choppingblock.h"

ChoppingBlock::ChoppingBlock(int x, int y) : MapBlock(CHOPPING_BLOCK, x, y)
{

}

bool ChoppingBlock::put_food(Food *f)
{
    return true;
}
