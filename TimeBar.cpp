#include "TimeBar.h"

TimeBar::TimeBar(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    start = std::time(NULL) + 30;
    // drew the time bar
    setPlainText(QString("TIME : ") + QString::number(start - std::time(NULL)));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Courier",30));
    // connect
    timer = new QTimer();
    this->connect(timer, SIGNAL(timeout()), this, SLOT(refleshTime()));
    timer->start(500);
}

TimeBar::~TimeBar()
{
    delete timer;
    scene() -> removeItem(this);
}

int TimeBar::getTime() {
    return (std::time(NULL) - start);
}

void TimeBar::refleshTime()
{
    int temp = start - std::time(NULL);
    if (temp >= 0) {
        setPlainText(QString("TIME : ") + QString::number(temp));
    } else if (temp == -1) {
        timeout();
     }
}


