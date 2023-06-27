
#ifndef MAPBLOCK_H
#define MAPBLOCK_H

#include <QLabel>
#include <enums.h>


class MapBlock
{
public:
    MapBlock(BlockType t, int x, int y);
private:
    QLabel *picture;
    int w, h;
    int x, y;
    BlockType t;
};

#endif // MAPBLOCK_H
