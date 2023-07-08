
#include "mapblock.h"

MapBlock::MapBlock(BlockType t, int x, int y, QWidget* parent) : x(x), y(y), t(t), parent(parent)
{
    switch (t) {
    case TABLE:
        w = 1, h = 1;
        picture = new QLabel(parent);
        //picture->setPicture();
        break;
    case TRASH_CAN:
        w = 1, h = 1;
        break;
    case RECEIVER:
        w = 2, h = 2;
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

BlockType MapBlock::type()
{
    return t;
}
