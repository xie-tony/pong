#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QElapsedTimer>
#include<QGraphicsTextItem>

class Countdown: public QGraphicsTextItem
{
public:
    Countdown();
    QElapsedTimer *cdtimer = new QElapsedTimer();
public slots:
    void changetime();
};

#endif // COUNTDOWN_H
