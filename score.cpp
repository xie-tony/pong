#include "score.h"
#include "game.h"
#include <QGraphicsTextItem>
#include <QFont>

extern Game *game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score1 = 0;
    score2 = 0;

    setPlainText(QString::number(score1) + QString("     ") + QString::number(score2)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));

}

void Score::increasescore1(){
    score1 = score1 + 1;
    setPlainText(QString::number(score1) + QString("     ") + QString::number(score2));
    if (score1 == 7){
        game->close();
    }
}

void Score::increasescore2(){
    score2 = score2 + 1;
    setPlainText(QString::number(score1) + QString("     ") + QString::number(score2));
    if (score2 == 7){
        game->close();
    }
}

QString Score::getscore(){
    return QString("sadsada");
}
