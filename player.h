#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>

class Player: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
