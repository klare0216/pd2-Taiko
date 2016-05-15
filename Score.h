#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QObject>
#include <QFont>

class Score : public QGraphicsTextItem {
    Q_OBJECT
public:
    Score(QGraphicsItem * parent = 0);
    ~Score();
    int getScore();
public slots:
    void changeScore(int x);
private:
    int score;
};
#endif // SCORE_H
