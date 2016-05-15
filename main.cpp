#include <QApplication>
#include <QObject>
#include <TaikoGame.h>


int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    TaikoGame * game = new TaikoGame();

    game->start();



    return a.exec();
}
