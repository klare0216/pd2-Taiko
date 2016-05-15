#ifndef TAIKO_H
#define TAIKO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include "HighNote.h"
#include "LowNote.h"
#include <typeinfo>
#include <string>
#include <cstdlib>
#include <ctime>

class Taiko : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Taiko();
    ~Taiko();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void start();
   // void loadNote(string file_name);
   // void saveNote(string file_name);
    int getScore();
public slots:
    void spawnNoteByMap();
signals:
    void changeScore(int x);
protected:
    int note_map[1000];
    int note_map_index;
    int score;
    QTimer  * timer;

};

#endif // TAIKO_H
