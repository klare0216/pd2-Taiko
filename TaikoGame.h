#ifndef TAIKOGAME_H
#define TAIKOGAME_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "Taiko.h"

#include "Score.h"
#include "TimeBar.h"
#include <QObject>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <QMediaPlayer>
#include <QUrl>
#include <QPushButton>
#include <QGraphicsTextItem>
#include <QObject>
#include <QFont>

class TaikoGame : public QObject {
    Q_OBJECT
public:
    TaikoGame();
    ~TaikoGame();
public slots:
    void start();
    void play();
    void end_page();
\
signals:
    void click_start();
private:
    QGraphicsScene  *scene_game;
    QGraphicsScene * scene_start;
    QGraphicsScene * scene_end;
    QGraphicsView *view;
    QMediaPlayer  *music;
    Taiko  * taiko;

    Score * score_bar;
    TimeBar  * time_bar;
    QPushButton * start_button;

    QPushButton * restart_button;
    QGraphicsTextItem * end_score;
    QGraphicsPixmapItem * bar;

};

#endif // TAIKOGAME_H
