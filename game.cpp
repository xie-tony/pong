#include "game.h"
#include "player.h"
#include "ai.h"
#include "countdown.h"
#include "ball.h"
#include <QMediaPlayer>
#include <QApplication>
#include <typeinfo>
#include <QGraphicsScene>
#include <QImage>
#include <QDebug>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,810,500);
    setScene(scene);
    //setBackgroundBrush(QBrush(QImage(":/image/bg.png")));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(810,500);

    setWindowTitle("PONG!");

    player= new Player();
    player->setRect(0,0,10,100);

    ball = new Ball();
    ball->setPos(400,250);


    ai = new Ai();

    score = new Score();

    countdown = new Countdown();

    scene->addItem(ball);
    scene->addItem(player);
    scene->addItem(ai);
    scene->addItem(score);
    scene->addItem(countdown);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus( );

    ai->setPos(790,200);
    player->setPos(10,200);
    score->setPos(370,10);
    countdown->setPos(380,300);

    QMediaPlayer *bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sound/bgm.mp3"));
    bgm->play();
    bgm->setVolume(75);

    show();
}
