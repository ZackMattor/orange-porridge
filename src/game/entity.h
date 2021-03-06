#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include <QDebug>

class Entity
{
public:
    sf::Vector2<float> getPosition();
protected:
    sf::Vector2<float> m_pos, m_vel;
    int m_id;
    double m_rotation;
    //something to tell if it's affected by gravity?
};

#endif // ENTITY_H
