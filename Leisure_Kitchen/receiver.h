#ifndef RECEIVER_H
#define RECEIVER_H

#include <vector>

#include <mapblock.h>
#include <orders.h>
#include <dish.h>
#include <food.h>


class Receiver : public MapBlock
{
public:
    Receiver(int x, int y, Orders* o, QWidget* parent);
    void receive(const std::vector<Food*>& v);
    void interact(Item*& i);
private:
    Orders* o;
};

#endif // RECEIVER_H
