
#ifndef MAPBLOCK_H
#define MAPBLOCK_H

#include <QLabel>
#include <QObject>
#include <enums.h>
#include <item.h>


class MapBlock : public QObject
{
public:
    MapBlock(BlockType t, int x, int y);
    BlockType type();
//    Item* pick_up();
//    bool put_down(Item* i);
private:
    QLabel *picture;
    int w, h;
    int x, y;
    BlockType t;
};

#endif // MAPBLOCK_H
