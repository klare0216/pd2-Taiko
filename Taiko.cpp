#include "Taiko.h"

Taiko::Taiko() {
    //drew a rect
    setPixmap(QPixmap(":/image/mtaikoflash_red.png"));
    setPos(50, 250);
    score = 0;
    srand(time(NULL));
    for(int i = 0;i < 1000;i++)
        note_map[i] = rand() % 3;
   note_map_index = 0;
   note_map[1] = note_map[10] =note_map[100] =1;
   note_map[15] = 1;
   note_map[12] = 2;
}

Taiko::~Taiko() {
    scene()->removeItem(this);
    delete timer;
}

void Taiko::keyPressEvent(QKeyEvent *event) {

    QList <QGraphicsItem *> colliding_items = collidingItems();


    if (event->key() == Qt::Key_A) {
        for(int i=0;i < colliding_items.length();i++)
        {
            if(typeid(* colliding_items[i]) == typeid(HighNote)) {
                delete  colliding_items[i];                
                changeScore(1);
                score++;
            }
        }
        //setRect(1, 1, 96, 96);
    }

    if (event->key() == Qt::Key_L) {
        for(int i=0;i < colliding_items.length();i++)
        {
            if(typeid(* colliding_items[i]) == typeid(LowNote)) {
                delete colliding_items[i];
                changeScore(1);
                score ++;
             }
        }
        //setRect(1, 1, 96, 96);
    }

}

void Taiko::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
       //setRect(0, 0, 100, 100);
    }

    if (event->key() == Qt::Key_L) {
        //setRect(0, 0, 100, 100);
    }

}

void Taiko::start() {
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnNoteByMap()));
    timer->start(500);
}

int Taiko::getScore()
{
    return score;
}

void Taiko::spawnNoteByMap()
{
    if (note_map_index < 1000) {
        if (note_map[note_map_index] == 1) {
            HighNote * new_note = new HighNote();
            scene()->addItem(new_note);
        } else if (note_map[note_map_index] == 2) {
            LowNote * new_note = new LowNote();
            scene()->addItem(new_note);
        }
        note_map_index++;
    }
}





