#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include <QDebug>
#include <QList>

#include "planet.h"

class Map
{
public:
    Map();

    void Draw(sf::RenderWindow*);
    void Update(sf::RenderWindow* = 0);
    sf::Texture* getBackground();
    sf::Vector2<float> getGravityOnPoint(sf::Vector2<float>, float);

private:
    sf::Texture m_background;

    QList<Planet*> m_planets;
};

#endif // MAP_H
