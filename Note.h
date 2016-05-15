#ifndef NOTE_H
#define NOTE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

// 要使用slot跟signal就必須繼承QObject
//一定要優先繼承QObject否則會出錯
class Note :public QObject , public QGraphicsPixmapItem  {
    Q_OBJECT
public:
    Note();
    ~Note();
public slots:
    void move();
protected:
    int width;
    int height;
    int wait_time;
    QTimer * timer;
};

#endif // NOTE_H
