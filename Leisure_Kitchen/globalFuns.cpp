
#include <enums.h>

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
QImage* Coin;
}

void InitPics()
{
    GamePics::Table = new QImage(":/Pictures/assets/Pictures/Table.jpg");
    GamePics::TrashCan = new QImage(":/Pictures/assets/Pictures/Trashcan.jpg");
    GamePics::ChoppingBlock = new QImage(":/Pictures/assets/Pictrues/ChoppingBlock.png");
    GamePics::Receiver = new QImage(":/Pictures/assets/Pictrues/Receiver.png");
    GamePics::Repository = new QImage(":/Pictures/assets/Pictrues/Repository.png");
    GamePics::CookingBench = new QImage(":/Pictures/assets/Pictrues/CookingBench.png");
    GamePics::Fish = new QImage(":/Pictures/assets/Pictrues/Fish.png");
    GamePics::Fish_Cut = new QImage(":/Pictures/assets/Pictrues/Fish_Cut.png");
    GamePics::Rice_Raw = new QImage(":/Pictures/assets/Pictrues/Rice_Raw.png");
    GamePics::Rice_Cooked = new QImage(":/Pictures/assets/Pictrues/Rice_Cooked.png");
    GamePics::HaiTai = new QImage(":/Pictures/assets/Pictrues/HaiTai.png");
    GamePics::Cucumber = new QImage(":/Pictures/assets/Pictrues/Cucumber.png");
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
    GamePics::Coin = new QImage(":/Pictures/assets/Pictures/Coin.png");
}

//not written yet
std::pair<int, int> pixel2Block(int x, int y)
{
    return { x, y };
}

std::pair<int, int> block2Pixel(int x, int y)
{
    return { x, y };
}
