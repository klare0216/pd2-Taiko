#include "LowNote.h"

LowNote::LowNote() : Note() {
    setPixmap(QPixmap(":/image/note_red.png"));
    width = 100;
    height = 100;
    wait_time = 10;
    setPos(800, 275);
    // connect
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(30);
}
