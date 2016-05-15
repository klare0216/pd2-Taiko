#include "TaikoGame.h"


TaikoGame::TaikoGame()
{
    taiko = 0;
    score_bar = 0;
    time_bar = 0;

    // create a view
    view = new QGraphicsView;
    // no more scrollbar
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800, 600);

    // create a QAudioDecoder
    music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sound/Run_Teens_Run.mp3"));


    // set scene_start
    // create a scene for start page
    scene_start = new QGraphicsScene;
    scene_start->setSceneRect(0, 0, 800, 600);
    scene_start->setBackgroundBrush(QBrush(QImage(":/image/img_31.jpg")));
    // create a buttom
    start_button = new QPushButton("START");
    start_button->setGeometry(QRect(QPoint(280, 500), QSize(200, 50)));
    start_button->setFont(QFont("Courier",18));
    start_button->resize(250, 50);
    scene_start->addWidget(start_button);
    connect(start_button, SIGNAL (released()), this, SLOT (play()));


    // set scene_game
    // create a scene for game
    scene_game = new QGraphicsScene;
    scene_game->setBackgroundBrush(QBrush(QImage(":/image/img_32.jpg")));
    scene_game->setSceneRect(0, 0, 800, 600);
    // create a bar
    bar = new QGraphicsPixmapItem;
    bar->setPixmap(QPixmap(":/image/bglayer_gogo.png"));
    bar->setPos(50,250);
    scene_game->addItem(bar);


    // set scene_end
    // create a scene for end page
    scene_end = new QGraphicsScene;
    scene_end->setSceneRect(0, 0, 800, 600);
    scene_end->setBackgroundBrush(QBrush(QImage(":/image/img_31.jpg")));
    // create a text item
    end_score = new QGraphicsTextItem;
    // drew the score bar
    end_score->setDefaultTextColor(Qt::black);
    end_score->setFont(QFont("Courier",30));
    end_score->setPos(100,200);
    scene_end->addItem(end_score);
    // create a buttom
    restart_button = new QPushButton("RESTART GAME");
    // set restart button
    restart_button->setGeometry(QRect(QPoint(280, 500), QSize(200, 50)));
    restart_button->resize(250, 50);
    restart_button->setFont(QFont("Courier",18));
    scene_end->addWidget(restart_button);

}

TaikoGame::~TaikoGame()
{
    delete scene_game;
    delete scene_start;
    delete scene_end;
    delete view;
    delete music;
    delete taiko;
    delete  score_bar;
    delete time_bar;
    delete start_button;
    delete  restart_button;
    delete end_score;
}


void TaikoGame::start() {
    view->setScene(scene_start);
    // show the view
    view->show();

}



void TaikoGame::play()
{
    delete taiko;
    delete score_bar;
    delete time_bar;

    // create a Taiko
    taiko = new Taiko;
    scene_game->addItem(taiko);
    // make taiko focusable
    taiko->setFlag(QGraphicsItem::ItemIsFocusable);
    taiko->setFocus();
    // create a score bar
    score_bar =  new Score;
    score_bar->setPos(50,100);
    scene_game->addItem(score_bar);
    //create a time bar
    time_bar = new TimeBar;
    scene_game->addItem(time_bar);
    time_bar->setPos(50,140);

    view->setScene(scene_game);
    view->show();
    music->setPosition(100*1000);
    music->play();
    taiko->start();

    QObject::connect(taiko, SIGNAL(changeScore(int)), score_bar, SLOT(changeScore(int)));
    QObject::connect(time_bar, SIGNAL(timeout()), this, SLOT(end_page()));

}

void TaikoGame::end_page()
{
    int score = score_bar->getScore();
    music->stop();

    // set score point
    end_score->setPlainText(QString("SCORE: ") + QString::number(score));

    view->setScene(scene_end);
    view->show();
    connect(restart_button, SIGNAL (released()), this, SLOT (play()));

}
