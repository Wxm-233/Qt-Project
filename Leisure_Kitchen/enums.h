
#ifndef ENUMS_H
#define ENUMS_H

#include <QImage>
#include <utility>

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

enum BlockType {
    TABLE, TRASH_CAN, CHOPPING_BLOCK,
    //桌子，垃圾桶，切菜桌
    RECEIVER, REPOSITORY, COOKING_BENCH
    //上菜处，食材仓库, 灶台
};

enum FoodType {
    FISH, RICE, HAITAI, CUCUMBER, CABBAGE, TOMATO
};

enum ItemType {
    POT, PLATE, FOOD
};

constexpr double PI = 3.1415926535897932384626;
constexpr int FPS = 60;
constexpr int PixelsPerBlock = 90;
constexpr int PixelsPerFood = 40;

void InitPics();

class Map;

std::pair<int, int> pixel2Block(int x, int y, Map* m);
std::pair<int, int> block2Pixel(int x, int y, Map* m);
QImage* fType2QImage(FoodType t);

namespace GamePics {
extern QImage* Table;
extern QImage* TrashCan;
extern QImage* ChoppingBlock;
extern QImage* Receiver;
extern QImage* Repository;
extern QImage* CookingBench;
extern QImage* Fish;
extern QImage* Fish_Cut;
extern QImage* Rice_Raw;
extern QImage* Rice_Cooked;
extern QImage* HaiTai;
extern QImage* Cucumber;
extern QImage* Cucumber_Cut;
extern QImage* Cabbage;
extern QImage* Cabbage_Cut;
extern QImage* Tomato;
extern QImage* Tomato_Cut;
extern QImage* Pot;
extern QImage* Plate;
extern QImage* Cook1;
extern QImage* Cook2;
extern QImage* BackGround;
}

//enum Cooking_Bench_Type {
//    WOK, FRYER, SAUCEPAN
//    //炒菜锅，油炸锅，煮饭锅
//};

//enum Raw_Food_Type {
//    FISH, HAMBERG_SLICE, CORN_PONE, CHICKEN,
//    //生鱼，汉堡片，玉米饼，鸡肉
//    POTATO_CHIPS, TOMATO, CABBAGE, RICE
//    //生土豆条，番茄，卷心菜，米
//};

//enum Processed_Food_Type {
//    SASHIMI, COOKED_SCROD, PROCESSED_CHICKEN, COOKED_CHICKEN,
//    //生鱼片，熟鱼片，切好的鸡肉，熟鸡肉
//    FRENCH_FRIES, TOMATO_SLICES, CABBAGE_SLICES
//    //炸薯条，
//};

//enum Cooked_Food_Type {

//};

#endif // ENUMS_H
