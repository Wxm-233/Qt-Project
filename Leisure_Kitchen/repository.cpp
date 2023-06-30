#include "repository.h"

Repository::Repository(FoodType t, int x, int y, QWidget* parent) : t(t), MapBlock(REPOSITORY, x, y, parent)
{

}

FoodType Repository::type()
{
    return t;
}
