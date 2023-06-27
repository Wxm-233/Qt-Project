#ifndef FOOD_H
#define FOOD_H
#include <enums.h>
#include <item.h>

class Food : public Item
{
public:
    Food(FoodType t, int x, int y);
    bool operator<(const Food& another) const;
    bool operator==(const Food& another) const;
private:
    FoodType type;
    bool isProcessed;
};

#endif // FOOD_H
