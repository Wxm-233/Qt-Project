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
    FoodType type();
    bool isProcessed();
    void process();
private:
    FoodType t;
    bool _isProcessed;
};

#endif // FOOD_H