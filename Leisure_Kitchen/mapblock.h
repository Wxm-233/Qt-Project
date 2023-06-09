
#ifndef MAPBLOCK_H
#define MAPBLOCK_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QPicture>
#include <QMovie>

#include <enums.h>
#include <item.h>
#include <plate.h>
#include <pot.h>
#include <food.h>


class MapBlock : public QObject
{
    Q_OBJECT

public:
    MapBlock(BlockType t, int x, int y, QWidget* parent);
    BlockType type();
protected:
    QLabel *picture;
    int w, h;//in blocks
    int x, y;//top left corner, in blocks
    BlockType t;
    QWidget* parent;
public slots:
    virtual void interact(Item*& i) = 0;
};

#endif // MAPBLOCK_H
