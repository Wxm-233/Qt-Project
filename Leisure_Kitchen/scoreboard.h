#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QPicture>
#include <QLabel>

#include <string>

class ScoreBoard : public QObject
{
    Q_OBJECT

public:
    ScoreBoard(QWidget* parent);
private:
    int score;
    QLabel* label;
public slots:
    void addScore(int dScore);
};

#endif // SCOREBOARD_H
