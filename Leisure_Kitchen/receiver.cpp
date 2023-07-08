#include "receiver.h"
#include <map.h>
#include <game.h>

Receiver::Receiver(int x, int y, Map* m, QWidget* parent) : MapBlock(RECEIVER, x, y, parent)
{
    picture = new QLabel(parent);
    picture->setPixmap(QPixmap::fromImage(*GamePics::Receiver));
    picture->resize(PixelsPerBlock,PixelsPerBlock);
    std::pair<int,int>pos=block2Pixel(x, y, (dynamic_cast<Game*>(parent))->m);
    picture->move(pos.first, pos.second);
}

void Receiver::receive(const std::vector<Food*>& v)
{
//    std::clog << "Received";
//    for (auto& i : v) {
//        std::clog << i->type() << ' ';
//    }
//    std::clog << std::endl;
    //emit receiveSignal(Dish(v));
}

void Receiver::interact(Item*& i)
{
    if (i != nullptr && i->type == PLATE) {
        this->receive(((Plate*)i)->dish());
        ((Plate*)(i))->clear();
    } 
}
