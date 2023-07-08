#ifndef TABLE_H
#define TABLE_H

#include <mapblock.h>
#include <item.h>
#include <enums.h>

class Table : public MapBlock
{
public:
    Table(Item* i, int x, int y, QWidget* parent);
    void interact(Item*& i);
    //Item* pick_up();
    //bool put_down(Item* i);
    //bool isEmpty();
    //Item* getItem();
private:
    Item* i;
};

#endif // TABLE_H
