#include "map.h"
#include <table.h>
#include <trashcan.h>
#include <choppingblock.h>
#include <receiver.h>
#include <repository.h>
#include <cookingbench.h>
#include <cstring>
#include <algorithm>

Map::Map(QWidget* parent,int x,int y,int w,int h) : parent(parent),_x(x),_y(y),_w(w),_h(h)
{
    memset(reachable,true,sizeof (reachable));
}

void Map::addBlock(QString BlockType, int x, int y, Item* item, FoodType ft)
{
    reachable[x][y]=false;
    if (BlockType == "Table") {
        map[{x, y}] = new Table(item, x, y, parent);
    }
    else if (BlockType == "TrashCan") {
        map[{x, y}] = new TrashCan(x, y, parent);
    }
    else if (BlockType == "ChoppingBlock") {
        map[{x, y}] = new ChoppingBlock(x, y, parent);
    }
    else if (BlockType == "Receiver") {
        Receiver* r = new Receiver(x, y, this, parent);
        map[{x, y}] = r;
        //connect(r, &Receiver::receive, this, &Map::receive);
    }
    else if (BlockType == "Repository") {
        map[{x, y}] = new Repository(ft, x, y, parent);
    }
    else if (BlockType == "CookingBench") {
        map[{x, y}] = new CookingBench(x, y, parent);
    }
}

bool Map::isReachable(int x, int y)
{
    x=(x-this->x())/PixelsPerBlock;
    y=(y-this->y())/PixelsPerBlock;
    if(! reachable[x][y]||x>=this->w()||x<0||y<0||y>=this->h())return false;
    return true;
}

MapBlock* Map::locate(int x, int y)
{
    x=(x-this->x())/PixelsPerBlock;
    y=(y-this->y())/PixelsPerBlock;
    if((this->map).find({x,y})!=(this->map).end())
        return map[{x,y}];
    else return nullptr;
}

int Map::x(){return _x;}
int Map::y(){return _y;}
int Map::w(){return _w;}
int Map::h(){return _h;}


void Map::init()
{
    QFile map2(":/MapResources/assets/MapResources/Map2.json");
    map2.open(QIODevice::ReadOnly);
    QByteArray qba = map2.readAll();
    QJsonDocument qjd = QJsonDocument::fromJson(qba);

    QJsonObject qjo = qjd.object();
    for (auto&& i = qjo.constBegin(); i != qjo.constEnd(); i++) {
        QString loc = i.key();
        std::string s = loc.toStdString();
        std::istringstream iss(s);
        int x, y;
        iss >> x;
        iss.get();
        iss >> y;
        std::pair<int, int> p = block2Pixel(x, y,this);
        int px = p.first, py = p.second;
        QJsonObject types = i.value().toObject();
        Item* item = nullptr;
        FoodType ft = HAITAI;
        if (!types["ItemType"].isNull()) {
            QString IType = types["ItemType"].toString();
            if (IType == "Pot") {
                item = new Pot(px, py, parent);
            }
            else if (IType == "Plate") {
                item = new Plate(px, py, parent);
            }
        }
        if (!types["FoodType"].isNull()) {
            QString FType = types["FoodType"].toString();
            if (FType == "Fish") {
                ft = FISH;
            }
            else if (FType == "Rice") {
                ft = RICE;
            }
            else if (FType == "HaiTai") {
                ft = HAITAI;
            }
            else if (FType == "Cucumber") {
                ft = CUCUMBER;
            }
            else if (FType == "Cabbage") {
                ft = CABBAGE;
            }
            else if (FType == "Tomato") {
                ft = TOMATO;
            }
        }
        addBlock(types["BlockType"].toString(), x, y, item, ft);
    }
}

void Map::receive(const Dish& d)
{
    emit receiveDish(d);
}
