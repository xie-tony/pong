#include "ball.h"
#include "score.h"
#include "player.h"
#include "ai.h"
#include "game.h"
#include <QtMath>
#include <QTimer>
#include <QElapsedTimer>
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <typeinfo>
#include <QDebug>
#include <QThread>

extern Game * game;

Ball::Ball()
{

    setRect(0,0,10,10);
    timer2->start();
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(16);

    bouncesound = new QMediaPlayer();
    bouncesound->setMedia(QUrl("qrc:/sound/bounce.wav"));
    bouncesound->setVolume(75);


}

void Ball::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player) or typeid(*(colliding_items[i])) == typeid(Ai) ){
            hdirection = 0 - hdirection;
            if (vdirection == 0){
                if (colliding_items[i]->y() - this->y() > -50){
                    vdirection = 1;
                } else {
                    vdirection = -1;
                }
            }
            if(x() < 100){
                setPos(x() + 1, y());
            } else {
                setPos(x() - 1, y());
            }
            bouncesound->play();
            int impactlocation = abs(colliding_items[i]->y() - this->y() + 50);
            qDebug() << impactlocation;
            vspeed = qLn(impactlocation) * 2;
            if (impactlocation == 0 ) {
                vspeed = 2;
            }
        }
    }
    if (x() <= 0 or x() >= 800){
        if (x() <= 0){
            game->score->increasescore2();
        } else {
            game->score->increasescore1();
        }
        this->setPos(400,200);
        timer2->restart();
        vdirection = 0;
        game->countdown->cdtimer->restart();
        game->ai->setPos(790,150);
        vspeed = 0;
        return;
    }
    if (y() < 0 or y() > 490){
        vdirection = 0 - vdirection;
    }
    if (timer2->elapsed() > 3000){
        setPos(x() - hspeed * hdirection, y() - vspeed * vdirection);
    }
}

