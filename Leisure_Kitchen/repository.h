#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <mapblock.h>
#include <enums.h>

class Repository : public MapBlock
{
public:
    Repository(FoodType t, int x, int y, QWidget* parent);
    FoodType type();
    void interact(Item*& i);
private:
    FoodType t;
    QLabel* food;
};

#endif // REPOSITORY_H
