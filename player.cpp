#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "ball.h"
#include <QDebug>

void Player::keyPressEvent(QKeyEvent *event){
    /*if (event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else */if (event->key() == Qt::Key_Up){
        if (y() > 10){
            setPos(x(),y()-20);
        } else if (y() <= 10 and y() > 5){
            setPos(x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_Down){
        if (y() < 390){
            setPos(x(),y()+25);
        } else if (y() >= 390 and y() < 395){
            setPos(x(),y()+10);
        }
    }
}

