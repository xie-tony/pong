#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QElapsedTimer>
#include <QMediaPlayer>
#include <QBrush>

class Ball: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Ball();
    double hdirection = 1;
    double vdirection = 1;
    double hspeed = 10;
    double vspeed = 0;
    QElapsedTimer *timer2 = new QElapsedTimer();
public slots:
    void move();
private:
    QMediaPlayer *bouncesound;
};

#endif // BALL_H
