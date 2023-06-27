#ifndef MAP_H
#define MAP_H
#include <enums.h>
#include <mapblock.h>
#include <map>
#include <QJsonObject>
#include <QJsonDocument>
#include <string>
#include <fstream>

class Map
{
public:
    Map();
    void addBlock();
    bool isReachable(int x, int y);
private:
    int w;
    int h;
    std::map<std::pair<int, int>, MapBlock> map;
    QJsonDocument qjd;
};

#endif // MAP_H
