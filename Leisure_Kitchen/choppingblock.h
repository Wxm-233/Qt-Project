#ifndef CHOPPINGBLOCK_H
#define CHOPPINGBLOCK_H

#include <QTimer>

#include "mapblock.h"

class ChoppingBlock : public MapBlock
{
public:
    ChoppingBlock(int x, int y, QWidget* parent);
    void putFood(Food* food);
private:
    QTimer* t = nullptr;
    Item* f = nullptr;
public slots:
    void interact(Item*& i);
};

#endif // CHOPPINGBLOCK_H
