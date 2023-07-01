#include "scoreboard.h"

ScoreBoard::ScoreBoard(QWidget* parent)
{
    label = new QLabel(parent);
    label->setGeometry(0, parent->y() - 50, 100, 50);
    label->setTextFormat(Qt::RichText);
    label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; \">Score:0</span></p></body></html>");
}

void ScoreBoard::addScore(int dScore)
{
    score += dScore;
    QString qs = "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; \">" + QString("Score:%1").arg(score) + "</span></p></body></html>";
    label->setText(qs);
}
