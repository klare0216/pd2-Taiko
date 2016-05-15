#ifndef TIMEBAR_H
#define TIMEBAR_H

#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QFont>
#include <ctime>
#include <QObject>
#include<QTimer>

class TimeBar :   public QGraphicsTextItem {
    Q_OBJECT
public:
   TimeBar(QGraphicsItem * parent = 0);
   ~TimeBar();
    int getTime();

public slots:
    void refleshTime();

signals:
    void timeout();

private:
    int start;
    QTimer * timer;
};

#endif // TIMEBAR_H
