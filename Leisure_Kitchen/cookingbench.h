#ifndef COOKINGBENCH_H
#define COOKINGBENCH_H

#include <QTimer>

#include <mapblock.h>

class CookingBench : public MapBlock
{
public:
    CookingBench(int x, int y, QWidget* parent);
    void interact(Item*& i);
    //bool put_down(Item* i);
    //Item* pick_up();
    //void processFood();
private:
    Item* p;
    QTimer* t;
};

//singleShot

#endif // COOKINGBENCH_H
