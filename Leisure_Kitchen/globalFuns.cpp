
#include <enums.h>
#include <map.h>

namespace GamePics {
QImage* Table;
QImage* TrashCan;
QImage* ChoppingBlock;
QImage* Receiver;
QImage* Repository;
QImage* CookingBench;
QImage* Fish;
QImage* Fish_Cut;
QImage* Rice_Raw;
QImage* Rice_Cooked;
QImage* HaiTai;
QImage* Cucumber;
QImage* Cucumber_Cut;
QImage* Cabbage;
QImage* Cabbage_Cut;
QImage* Tomato;
QImage* Tomato_Cut;
QImage* Pot;
QImage* Plate;
QImage* Cook1;
QImage* Cook2;
QImage* BackGround;
}

void InitPics()
{
    GamePics::Table = new QImage(":/Pictures/assets/Pictures/Table.jpg");
    GamePics::TrashCan = new QImage(":/Pictures/assets/Pictures/TrashCan.png");
    GamePics::ChoppingBlock = new QImage(":/Pictures/assets/Pictures/ChoppingBlock.png");
    GamePics::Receiver = new QImage(":/Pictures/assets/Pictures/Receiver.png");
    GamePics::Repository = new QImage(":/Pictures/assets/Pictures/Repository.png");
    GamePics::CookingBench = new QImage(":/Pictures/assets/Pictures/CookingBench.png");
    GamePics::Fish = new QImage(":/Pictures/assets/Pictures/Fish.png");
    GamePics::Fish_Cut = new QImage(":/Pictures/assets/Pictures/Fish_Cut.png");
    GamePics::Rice_Raw = new QImage(":/Pictures/assets/Pictures/Rice_Raw.png");
    GamePics::Rice_Cooked = new QImage(":/Pictures/assets/Pictures/Rice_Cooked.png");
    GamePics::HaiTai = new QImage(":/Pictures/assets/Pictures/Haitai.png");
    GamePics::Cucumber = new QImage(":/Pictures/assets/Pictures/Cucumber.png");
    GamePics::Cucumber_Cut = new QImage(":/Pictures/assets/Pictures/Cucumber_Cut.png");
    GamePics::Cabbage = new QImage(":/Pictures/assets/Pictures/Cabbage.png");
    GamePics::Cabbage_Cut = new QImage(":/Pictures/assets/Pictures/Cabbage_Cut.png");
    GamePics::Tomato = new QImage(":/Pictures/assets/Pictures/Tomato.png");
    GamePics::Tomato_Cut = new QImage(":/Pictures/assets/Pictures/Tomato_Cut.png");
    GamePics::Pot = new QImage(":/Pictures/assets/Pictures/Pot.png");
    GamePics::Plate = new QImage(":/Pictures/assets/Pictures/Plate.png");
    GamePics::Cook1 = new QImage(":/Pictures/assets/Pictures/Cook1.png");
    GamePics::Cook2 = new QImage(":/Pictures/assets/Pictures/Cook2.png");
    GamePics::BackGround = new QImage(":/Pictures/assets/Pictures/BackGround.jpg");
}

std::pair<int, int> pixel2Block(int x, int y, Map* m)
{
    int ret_x = (x-m->x())/PixelsPerBlock;
    int ret_y = (y-m->y())/PixelsPerBlock;
    return { ret_x, ret_y };
}

std::pair<int, int> block2Pixel(int x, int y, Map* m)
{
    int ret_x=m->x()+PixelsPerBlock*x;
    int ret_y=m->y()+PixelsPerBlock*y;
    return { ret_x, ret_y };
}

QImage* fType2QImage(FoodType t)
{
    switch (t) {
    case FISH:
        return GamePics::Fish;
    case RICE:
        return GamePics::Rice_Raw;
    case HAITAI:
        return GamePics::HaiTai;
    case CUCUMBER:
        return GamePics::Cucumber;
    case CABBAGE:
        return GamePics::Cabbage;
    case TOMATO:
        return GamePics::Tomato;
    default:
        return nullptr;
    }
}
