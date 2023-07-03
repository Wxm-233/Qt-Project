#include <enums.h>
#include "character.h"

Character::Character(QWidget *parent, int x, int y) : x(x), y(y), facing(0), i(nullptr)
{
    //img = new QImage(":/Pictures/assests/Pictures/test_Character.png");
    image = new QImage(*GamePics::Cook1);
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*image));
    picture->resize(image->width(), image->height());
    qtf = new QTransform;
    //picture->resize(60, 60);
    //picture->setPixmap(QPixmap::fromImage(*img));
    picture->move(x - 50, y - 50);
    facing = PI*3/2;
    //picture->show();
}

void Character::move(bool directionState[4], Map* m)
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

    double newFacing;

    if (x_dir == 0) {
        newFacing = y_dir == 0 ? facing : y_dir < 0 ? PI/2 : 3*PI/2;
    } else {
        double atan = std::atan(double(-y_dir/x_dir));
        newFacing = atan == 0 ? (x_dir > 0 ? 0 : PI) : ((atan > 0 ? atan : atan + PI) + (y_dir < 0 ? 0 : PI));
    }

    if (newFacing != facing) {
        qtf->rotate((facing - newFacing) / PI * 180);
        std::clog << "dtheta:" << (facing - newFacing) / PI * 180 << std::endl;
//        std::clog << qtf->m11() << ' ' << qtf->m12() << ' ' << qtf->m13() << std::endl
//            << qtf->m21() << ' ' << qtf->m22() << ' ' << qtf->m23() << std::endl
//            << qtf->m31() << ' ' << qtf->m32() << ' ' << qtf->m33() << std::endl << std::endl;
        *image = GamePics::Cook1->transformed(*qtf);
        picture->setPixmap(QPixmap::fromImage(*image));
        picture->resize(image->width(), image->height());
    }



    //std::clog << facing << std::endl;
    //qDebug() << facing;
    facing = newFacing;

    picture->move(x, y);

    if (i == nullptr)
        return;

    int itemx = x + w * (1 + std::cos(facing)) / 2;
    int itemy = y + h * (1 - std::sin(facing)) / 2;
    i->move(itemx, itemy);
}

void Character::dash(Map* m)
{
    if (isPaused)
        return;

    int new_x = x + 10 * speed * std::cos(facing);
    int new_y = y - 10 * speed * std::sin(facing);
    x = m->isReachable(new_x, y) ? new_x : x;
    y = m->isReachable(x, new_y) ? new_y : y;

    picture->move(x, y);

    if (i == nullptr)
        return;

    int itemx = x + w * (1 + std::cos(facing)) / 2;
    int itemy = y + h * (1 - std::sin(facing)) / 2;
    i->move(itemx, itemy);
}

void Character::pause()
{
    isPaused = true;
}

void Character::resume()
{
    isPaused = false;
}

void Character::interact(Map* m)
{
    int dest_x = this->x + this->w / 2 + (PixelsPerBlock / 2 + this->w / 2) * cos(facing);
    int dest_y = this->y + this->h / 2 - (PixelsPerBlock / 2 + this->h / 2) * sin(facing);
    MapBlock* mb = m->locate(dest_x, dest_y);
    if (mb == nullptr)
        return;
}

//void Character::interact(int x, int y)
//{

//}

//void Character::clearItem()
//{
//    this->i = nullptr;
//}

Character::~Character()
{

}
