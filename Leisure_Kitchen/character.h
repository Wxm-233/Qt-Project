
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
    Map* m;
    bool isPaused = false;
public:
    Character(QWidget *parent = nullptr, int x = 0, int y = 0);
    ~Character();
    void dash();
    void move(bool directionState[4]);
    void pause();
    void resume();
signals:

};

#endif // CHARACTER_H
