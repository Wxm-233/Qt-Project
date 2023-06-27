
#include "character.h"

Character::Character(QWidget *parent, int x, int y) : x(x), y(y)
{
    img = new QImage(":/Pictures/assests/Pictures/test_Character.png");
    picture = new QLabel(parent);
    picture->resize(img->width(), img->height());
    picture->setPixmap(QPixmap::fromImage(*img));
    picture->move(x - 50, y - 50);
    //picture->show();
}

void Character::move(bool directionState[4])
{
    if (isPaused)
        return;

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

    int new_x = x + speed * x_dir;
    int new_y = y + speed * y_dir;

    x = m->isReachable(new_x, y) ? new_x : x;
    y = m->isReachable(x, new_y) ? new_y : y;

    if (x_dir == 0) {
        facing = y_dir == 0 ? facing : y_dir < 0 ? PI/2 : 3*PI/2;
    } else {
        double atan = std::atan(double(-y_dir/x_dir));
        facing = atan == 0 ? (x_dir > 0 ? 0 : PI) : ((atan > 0 ? atan : atan + PI) + (y_dir < 0 ? 0 : PI));
    }

    //std::clog << facing << std::endl;

    picture->move(x, y);
}

void Character::dash()
{
    if (isPaused)
        return;

    int new_x = x + 10 * speed * std::cos(facing);
    int new_y = y - 10 * speed * std::sin(facing);
    x = m->isReachable(new_x, y) ? new_x : x;
    y = m->isReachable(x, new_y) ? new_y : y;

    picture->move(x, y);
}

void Character::pause()
{
    isPaused = true;
}

void Character::resume()
{
    isPaused = false;
}

Character::~Character()
{

}
