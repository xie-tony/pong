#ifndef AI_H
#define AI_H

#include <QGraphicsRectItem>
#include <QObject>

class Ai: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Ai();
    int direction = 1;
public slots:
    void move();
};

#endif // AI_H
