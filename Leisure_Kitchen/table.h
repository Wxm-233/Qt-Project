#ifndef TABLE_H
#define TABLE_H
#include <mapblock.h>
#include <item.h>

class Table : public MapBlock
{
public:
    Table(Item* i, int x, int y);
    Item* pick_up();
    bool put_down(Item* i);
private:
    Item* i;
};

#endif // TABLE_H
