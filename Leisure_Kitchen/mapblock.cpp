
#include "mapblock.h"

MapBlock::MapBlock(BlockType t, int x, int y) : x(x), y(y), t(t)
{
    switch (t) {
    case TABLE:
        w = 1, h = 1;
        //picture =
        break;
    case CHOPPING_BLOCK:
        w = 1, h = 1;
        break;
    case TRASH_CAN:
        w = 1, h = 1;
        break;
    case SINK:
        w = 2, h = 1;
        break;
    case RECEIVER:
        w = 2, h = 2;
        break;
    case DISHES_BLOCK:
        w = 1, h = 1;
        break;
    case REPOSITORY:
        w = 1, h = 1;
        break;
    case COOKING_BENCH:
        w = 1, h = 1;
        break;
    default:
        break;
    }
}

