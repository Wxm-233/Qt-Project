#ifndef RECEIVER_H
#define RECEIVER_H
#include <mapblock.h>
#include <orders.h>
#include <dish.h>
#include <food.h>
#include <vector>

class Receiver : public MapBlock
{
public:
    Receiver(int x, int y, Orders* o);
    void receive(const std::vector<Food>& v);
private:
    Orders* o;
};

#endif // RECEIVER_H
