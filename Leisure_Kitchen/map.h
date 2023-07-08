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
    Map(QWidget* parent,int x,int y, int w,int h);
    void addBlock(QString BlockType, int x, int y, Item* item, FoodType ft);
    bool isReachable(int x, int y);//x,y are pixels
    MapBlock* locate(int x, int y);//x,y are pixels
    void init();
    int x();
    int y();
    int w();
    int h();
    bool reachable[20][20];
private:
    QWidget* parent;
    std::map<std::pair<int, int>, MapBlock*> map;
    QJsonDocument qjd;
    int _x;
    int _y;
    int _w;
    int _h;
signals:
    void receiveDish(const Dish& d);
public slots:
    void receive(const Dish& d);
};

#endif // MAP_H
