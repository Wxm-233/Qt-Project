#include "map.h"
#include <table.h>
#include <trashcan.h>
#include <choppingblock.h>
#include <receiver.h>
#include <repository.h>
#include <cookingbench.h>

Map::Map(QWidget* parent) : parent(parent)
{

}

void Map::addBlock(QString BlockType, int x, int y, Item* item, FoodType ft)
{
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
        map[{x, y}] = new Receiver(x, y, this, parent);
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
    return true;
}

MapBlock* Map::locate(int x, int y)
{
    return nullptr;
}

void Map::init()
{
    QFile map1(":/MapResources/assets/MapResources/Map1.json");
    map1.open(QIODevice::ReadOnly);
    QByteArray qba = map1.readAll();
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
        std::pair<int, int> p = block2Pixel(x, y);
        int px = p.first, py = p.second;
        QJsonObject types = i.value().toObject();
        Item* item = nullptr;
        FoodType ft = HAITAI;
        if (!types["ItemType"].isNull()) {
            QString IType = types["ItemType"].toString();
            if (IType == "Pot") {
                item = new Pot(px, py);
            }
            else if (IType == "Plate") {
                item = new Plate(px, py);
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
