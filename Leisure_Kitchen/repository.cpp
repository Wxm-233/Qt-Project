#include "repository.h"

Repository::Repository(FoodType t, int x, int y) : t(t), MapBlock(REPOSITORY, x, y)
{

}

FoodType Repository::type()
{
    return t;
}
