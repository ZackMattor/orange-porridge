#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

#include <QDebug>
#include <QCoreApplication>
#include <QtCore/QTime>

#include "gameManager.h"
#include "globals.h"

class engine
{
public:
    engine();

    int init();
    void run();
private:
    gameManager *m_gameInstance;
    sf::RenderWindow *m_window;

    bool m_keys[255] = {false};
};

#endif // ENGINE_H
