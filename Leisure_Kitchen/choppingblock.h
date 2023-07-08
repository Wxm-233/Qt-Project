#ifndef CHOPPINGBLOCK_H
#define CHOPPINGBLOCK_H

#include <QTimer>

#include "mapblock.h"

class ChoppingBlock : public MapBlock
{
public:
    ChoppingBlock(int x, int y, QWidget* parent);
    ~ChoppingBlock();
    void putFood(Item*& food);
    Item*& food();
    void cutFood();
    bool isCutting();
private:
    QTimer* t = nullptr;
    Item* f = nullptr;
    bool _isCutting;
    QMovie* movie;
    QLabel* processing;
public slots:
    void interact(Item*& i);
};

#endif // CHOPPINGBLOCK_H
