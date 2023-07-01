
#ifndef MAPBLOCK_H
#define MAPBLOCK_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QPicture>

#include <enums.h>
#include <item.h>
#include <plate.h>
#include <pot.h>
#include <food.h>


class MapBlock : public QObject
{
public:
    MapBlock(BlockType t, int x, int y, QWidget* parent);
    BlockType type();
private:
    QLabel *picture;
    int w, h;//in blocks
    int x, y;//top left corner, in blocks
    BlockType t;
public slots:
    virtual void interact(Item*& i) = 0;
};

#endif // MAPBLOCK_H
