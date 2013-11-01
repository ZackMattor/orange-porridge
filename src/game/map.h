#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include <QDebug>
#include <QList>

class Map
{
public:
    Map();

    void Draw(sf::RenderWindow*);
    void Update(sf::RenderWindow* = 0);

private:
    sf::Texture m_background;
    sf::Texture m_planet;
    double m_planetRotation;
};

#endif // MAP_H
