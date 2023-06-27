
#ifndef ENUMS_H
#define ENUMS_H

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

enum BlockType {
    TABLE, CHOPPING_BLOCK, TRASH_CAN,
    //桌台，砧板，垃圾桶
    SINK, RECEIVER, DISHES_BLOCK, REPOSITORY, COOKING_BENCH
    //洗碗池，上菜处，盘子出现的地方，食材仓库, 灶台
};

enum FoodType {
    FISH, RICE, HAITAI, CUCUMBER, CABBAGE, TOMATO
};

enum ItemType {
    COOKER, PLATE, FOOD
};

constexpr double PI = 3.1415926535897932384626;
constexpr int FPS = 60;
constexpr int PixelsPerBlock = 100;

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
