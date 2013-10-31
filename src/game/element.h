#ifndef ELEMENT_H
#define ELEMENT_H

#include <SFML/Graphics.hpp>

#include <QDebug>

class Element
{
public:
protected:
    sf::Vector2<double> m_pos, m_vel;
    int m_id;
    double m_rotation;
    //something to tell if it's affected by gravity?
};

#endif // ELEMENT_H
