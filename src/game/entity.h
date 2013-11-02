#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include <QDebug>

class Entity
{
public:
    sf::Vector2<double> getPlayerPosition();
protected:
    sf::Vector2<double> m_pos, m_vel;
    int m_id;
    double m_rotation;
    //something to tell if it's affected by gravity?
};

#endif // ENTITY_H
