#ifndef SCOREANDTIME_H
#define SCOREANDTIME_H
#include <ctime>
#include <QGraphicsTextItem>

class ScoreAndTime : public QGraphicsTextItem {
public:
    ScoreAndTime();

private:
    int score;
    t_time start_time;
    t_time now_time;
};

#endif // SCOREANDTIME_H
