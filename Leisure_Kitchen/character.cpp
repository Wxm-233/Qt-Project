
#include "character.h"

Character::Character(QWidget *parent, int x, int y) : x(x), y(y)
{
    img = new QImage(":/Pictures/assests/Pictures/test_Character.png");
    picture = new QLabel(parent);
    picture->resize(img->width(), img->height());
    picture->setPixmap(QPixmap::fromImage(*img));
    picture->setGeometry(x - 50, y - 50, img->width(), img->height());
    picture->show();
}

void Character::move(bool directionState[4])
{
    int x_dir = 0;
    int y_dir = 0;

    if (directionState[UP]) {
        y_dir -= 1;
    }
    if (directionState[DOWN]) {
        y_dir += 1;
    }
    if (directionState[LEFT]) {
        x_dir -= 1;
    }
    if (directionState[RIGHT]) {
        x_dir += 1;
    }

    x += speed * x_dir;
    y += speed * y_dir;

    if (x == 0) {
        facing = y == 0 ? facing : y > 0 ? PAI/2 : 3*PAI/2;
    } else {
        facing = y < 0 ? PAI : 0 + std::atan(double(y/x));
    }

    picture->setGeometry(x, y, picture->width(), picture->height());
}

void Character::dash()
{
    x += 10 * speed * std::cos(facing);
    y += 10 * speed * std::sin(facing);

    picture->setGeometry(x, y, picture->width(), picture->height());
}

Character::~Character()
{

}
