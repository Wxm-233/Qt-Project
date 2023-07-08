#ifndef ITEM_H
#define ITEM_H

#include <QPicture>
#include <QLabel>
#include <QObject>
#include <QWidget>

#include <enums.h>

class Item : public QObject
{
    Q_OBJECT

public:
    Item(ItemType, int x, int y, QWidget* parent);
    ~Item();
    virtual void interact(Item*& rThis, Item*& rAnother) = 0;
    ItemType type;
    void move(int x, int y);//in pixels
protected:
    int w = 1, h = 1;
    int x, y;
    QLabel* picture;
    QWidget* parent;
};

#endif // ITEM_H
