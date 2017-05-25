#include "countdown.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>

Countdown::Countdown()
{
    setPlainText("3.000");
    setDefaultTextColor(Qt::red);
    setFont(QFont("KaiTi",64));

    QTimer * timer = new QTimer();
    connect(timer, &QTimer::timeout ,this , &Countdown::changetime);
    timer->start(10);

    cdtimer->restart();
}

void Countdown::changetime()
{
    if (cdtimer->elapsed() < 3000){
        setPlainText(QString::number(3 - cdtimer->elapsed() / 1000));
    } else {
        setPlainText(" ");
    }
}

