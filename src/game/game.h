#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include <QDebug>
#include <math.h>

#include "globals.h"
#include "player.h"
#include "map.h"

class Game
{
public:
    Game();

    void draw(sf::RenderWindow *);
    void update(sf::View *camera, sf::RenderWindow * = 0);

    void drawBackground(sf::RenderWindow *window);
private:
    Player *m_player;
    Map *m_map;
};

#endif // GAME_H
