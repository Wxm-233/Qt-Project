
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
    int x, y;//coordinate of the top left corner
    int w, h;//in pixels
    double facing;//an angle ranging from 0 to 2pi
    Item* i;//the object in the character's hand
    bool isPaused = false;//status of the character
public:
    Character(QWidget *parent, int x, int y);//(x, y) is the coordinate of the top left corner
    ~Character();
    void dash(Map* m);//m is from the parent Game class
    void move(bool directionState[4], Map* m);
    //void interact(int x, int y);//mouse click event
    void interact(Map* m);//when the player presses down the interact button

public slots:
    void pause();
    void resume();
signals:

};

#endif // CHARACTER_H
