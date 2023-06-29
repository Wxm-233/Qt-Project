
#ifndef CHARACTER_H
#define CHARACTER_H


#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QKeyEvent>
#include <QImage>
#include <QPixmap>
#include <iostream>
#include <cmath>
#include <enums.h>
#include <map.h>
#include <table.h>
#include <item.h>
#include <pot.h>
#include <plate.h>
#include <choppingblock.h>

class Character : public QObject
{
    Q_OBJECT
private:
    const static int speed = 10;
    QLabel *picture;
    QImage *img;
    int x, y;
    int w, h;
    double facing;
    Item* i;
    bool isPaused = false;
public:
    Character(QWidget *parent = nullptr, int x = 0, int y = 0);
    ~Character();
    void dash(Map* m);
    void move(bool directionState[4], Map* m);
    void pause();
    void resume();
    //void interact(int x, int y);
    void interact(Map* m);
signals:

};

#endif // CHARACTER_H
