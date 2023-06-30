#ifndef ITEM_H
#define ITEM_H

#include <QPicture>
#include <QLabel>

#include <enums.h>

class Item
{
public:
    Item(ItemType, int x, int y);
    ~Item();
    virtual void interact(Item*& rThis, Item*& rAnother) = 0;
    ItemType type;
    void move(int x, int y);//in pixels
private:
    int w = 1, h = 1;
    int x, y;
    QLabel* label;
    
};

#endif // ITEM_H
