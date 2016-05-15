#include "Note.h"


Note::Note() {
    // drew picture

   //width = 100;
   //height = 100;
   wait_time = 10;
   setPos(800, 275);
   // connect
   timer = new QTimer();
   connect(timer, SIGNAL(timeout()), this, SLOT(move()));
   timer->start(40);
}

Note::~Note() {
    delete timer;
    scene() -> removeItem(this);
}

void Note::move() {


    if (pos().x() > 75) {
        setPos(x()-2,y());
    }

     // delete
    if (pos().x() <= 75) {
        wait_time --;
    }
    if (wait_time == 0) {
        delete this;
    }
}
