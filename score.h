#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent=0);
    void increasescore1();
    void increasescore2();
    QString getscore();

    int score1;
    int score2;
};

#endif // SCORE_H
