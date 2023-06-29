#include "map.h"

Map::Map()
{
    QByteArray qba;
    std::fstream f;
    f.open(":/MapResources/assests/MapResources/Map1");
    std::string s;
    f >> s;
    qba.fromStdString(s);
    qjd.fromJson(qba);
}

bool Map::isReachable(int x, int y)
{
    return true;
}

MapBlock* Map::locate(int x, int y)
{
    return nullptr;
}
