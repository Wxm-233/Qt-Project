#ifndef ITEM_H
#define ITEM_H

#include <QPicture>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QMovie>

#include <enums.h>

class Item : public QObject
{
    Q_OBJECT

public:
    Item(ItemType, int x, int y, QWidget* parent);
    ~Item();
    virtual void interact(Item*& rThis, Item*& rAnother) = 0;
    ItemType type;
    virtual void move(int x, int y);//in pixels
    void show();
    void hide();
protected:
    int w = 1, h = 1;
    int x, y;
    QLabel* picture;
    QWidget* parent;
};

#endif // ITEM_H
