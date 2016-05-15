#include "Score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    score = 0;
    // drew the score bar
    setPlainText(QString("SCORE: ") + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Courier",30));
}

Score::~Score()
{

    scene()->removeItem(this);
}

int Score::getScore() {
    return score;
}

void Score::changeScore(int x)
{
    score += x;
    setPlainText(QString("SCORE: ") + QString::number(score));
}

