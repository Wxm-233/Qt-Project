
#ifndef CHARACTER_H
#define CHARACTER_H


#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QKeyEvent>
#include <QImage>
#include <QPixmap>
#include <cmath>
#include <enums.h>

class Character : public QObject
{
    Q_OBJECT
private:
    const static int speed = 20;
    QLabel *picture;
    QImage *img;
    int x;
    int y;
    double facing;
public:
    Character(QWidget *parent = nullptr, int x = 0, int y = 0);
    ~Character();
    void dash();
    void move(bool directionState[4]);
    void pause();
signals:

};

#endif // CHARACTER_H
