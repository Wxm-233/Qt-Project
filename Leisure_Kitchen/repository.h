#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <mapblock.h>
#include <enums.h>

class Repository : public MapBlock
{
public:
    Repository(FoodType t, int x, int y);
    FoodType type();
private:
    FoodType t;
};

#endif // REPOSITORY_H
