#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <QPicture>
#include <QLabel>
#include <string>


class ScoreBoard
{
public:
    ScoreBoard(QWidget* parent);
    void addScore(int dScore);

private:
    int score;
    QLabel* label;
};

#endif // SCOREBOARD_H
