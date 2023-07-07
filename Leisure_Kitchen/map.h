#ifndef MAP_H
#define MAP_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <QObject>
#include <QFile>

#include <map>
#include <string>
#include <sstream>
#include <fstream>

#include <enums.h>
#include <item.h>
#include <mapblock.h>
#include <dish.h>

class Map : public QObject
{
    Q_OBJECT

public:
    Map(QWidget* parent);
    void addBlock(QString BlockType, int x, int y, Item* item, FoodType ft);
    bool isReachable(int x, int y);
    MapBlock* locate(int x, int y);
    void init();
    void receive(const Dish& d);
private:
    QWidget* parent;
    std::map<std::pair<int, int>, MapBlock*> map;
    QJsonDocument qjd;
signals:
    void receiveDish(const Dish& d);
};

#endif // MAP_H
