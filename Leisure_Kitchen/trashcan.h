#ifndef TRASHCAN_H
#define TRASHCAN_H

#include <mapblock.h>

class TrashCan : public MapBlock
{
public:
    TrashCan(int x, int y, QWidget* parent);
    void interact(Item*& i);
private:

};

#endif // TRASHCAN_H
