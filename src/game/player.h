#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include <QDebug>
#include <QtCore/qmath.h>

#include "entity.h"
#include "globals.h"

class Player : public Entity
{
public:
    Player();

    void Draw(sf::RenderWindow*);
    void Update(sf::RenderWindow* = 0);

    void thrustFoward();
    void thrustReverse();

private:
    sf::Texture m_texture;
    float m_thrust = 0.15;
};

#endif // PLAYER_H
