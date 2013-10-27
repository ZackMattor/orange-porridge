#include <QCoreApplication>
#include <QDebug>

#include <QtCore/QTime>
#include "globals.h"

#include "engine.h"

int main(int argc, char *argv[])
{
    engine *gameEngine = new engine();

    //Blocking function, runs game server
    gameEngine->run();

    QCoreApplication a(argc, argv);
    return 1;
}
