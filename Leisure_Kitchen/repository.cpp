#include "repository.h"

Repository::Repository(FoodType t, int x, int y, QWidget* parent) : t(t), MapBlock(REPOSITORY, x, y, parent)
{

}

FoodType Repository::type()
{
    return t;
}

void Repository::interact(Item*& i)
{
    if (i == nullptr) {
        i = new Food(t, 0, 0);
    }
}