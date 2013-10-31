#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include <QDebug>

#include "element.h"

class Player : public Element
{
public:
    Player();

    void Draw(sf::RenderWindow*);
    void Update(sf::RenderWindow* = 0);
};

#endif // PLAYER_H
