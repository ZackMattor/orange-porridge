#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include <QDebug>

#include "globals.h"
#include "element.h"
#include "player.h"

class Game
{
public:
    Game();

    void draw(sf::RenderWindow *);
    void update(sf::RenderWindow * = 0);
private:
    Player *m_player;
};

#endif // GAME_H
