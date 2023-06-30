#ifndef MAP_H
#define MAP_H

#include <QJsonObject>
#include <QJsonDocument>

#include <map>
#include <string>
#include <fstream>

#include <enums.h>
#include <mapblock.h>

class Map
{
public:
    Map();
    void addBlock();
    bool isReachable(int x, int y);
    MapBlock* locate(int x, int y);
private:
    int w;
    int h;
    std::map<std::pair<int, int>, MapBlock*> map;
    QJsonDocument qjd;
};

#endif // MAP_H
