#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "score.h"
#include "ai.h"
#include "ball.h"
#include "countdown.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Score *score;
    Countdown *countdown;
    Player *player;
    Ai *ai;
    Ball *ball;

};

#endif // GAME_H
