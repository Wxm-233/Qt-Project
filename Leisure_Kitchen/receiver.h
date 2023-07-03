#ifndef RECEIVER_H
#define RECEIVER_H

#include <vector>

#include <mapblock.h>
#include <dish.h>
#include <food.h>

class Map;

class Receiver : public MapBlock
{
public:
    Receiver(int x, int y, Map* m, QWidget* parent);
    void receive(const std::vector<Food*>& v);
    void interact(Item*& i);
private:
    Map* m;
};

#endif // RECEIVER_H
