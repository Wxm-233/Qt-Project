#include "scoreboard.h"

ScoreBoard::ScoreBoard(QWidget* parent)
{
    label = new QLabel(parent);
    label->setGeometry(0, parent->y() - label->height(), label->width(), label->height());

}

void ScoreBoard::addScore(int dScore)
{
    score += dScore;
    QString qs = QString("Score:%1").arg(score);
    label->setText(qs);
}
