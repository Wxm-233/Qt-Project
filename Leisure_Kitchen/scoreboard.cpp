#include "scoreboard.h"
#include <game.h>
#include <ui_game.h>

ScoreBoard::ScoreBoard(QWidget* parent) : parent(parent)
{
    Game* g = dynamic_cast<Game*>(parent);
    label = new QLabel(g->ui->label_8);
    label->setGeometry(0, 0, 200, 100);
    label->setTextFormat(Qt::RichText);
    label->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; \">Score:0</span></p></body></html>");
}

void ScoreBoard::addScore(int dScore)
{
    score += dScore;
    QString qs = "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; \">" + QString("Score:%1").arg(score) + "</span></p></body></html>";
    label->setText(qs);
}
