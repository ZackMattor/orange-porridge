#ifndef ENGINE_H
#define ENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include <SFML/Graphics.hpp>

#include <QCoreApplication>
#include <QDebug>

#include <QtCore/QTime>
//#include "gameManager.h"
#include "globals.h"

class engine
{
public:
    engine();

    int init();
    void run();
private:
    //gameManager *m_gameInstance;
    sf::RenderWindow m_window;

    bool m_keys[255] = {false};
    ALLEGRO_MOUSE_EVENT m_mouse;
    ALLEGRO_DISPLAY *m_display = NULL;
    ALLEGRO_BITMAP *m_background = NULL;
};

#endif // ENGINE_H
