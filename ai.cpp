#include "ai.h"
#include "game.h"
#include "ball.h"
#include <QTimer>
#include <stdlib.h>
#include <typeinfo>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game * game;

Ai::Ai()
{

    setRect(0,0,10,100);

    QTimer * timer = new QTimer();
    connect(timer, &QTimer::timeout ,this , &Ai::move);

    timer->start(20);
}

void Ai::move(){
    if (game->countdown->cdtimer->elapsed() > 3300){
        QList<QGraphicsItem *> obs = scene()->items();
        if ((abs(y() - obs[4]->y()) < 50 and abs(x() - obs[4]->x()) > 450) or ((y() - obs[4]->y() < 70 and y() - obs[4]->y() > 0) and abs(x() - obs[4]->x()) < 30)){
            direction = 0;
        }else if (y() <= obs[4]->y() - 50){
            if (y() < 390){
                direction = 1;
            } else {
                direction = 0;
            }
        } else {
            if (y() > 10){
                direction = -1;
            } else {
                direction = 0;
            }
        }
        setPos(x(),y() + 13 * direction);
    }
}
