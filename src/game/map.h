#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include <QDebug>

class Map
{
public:
    Map();

    void Draw(sf::RenderWindow*);
    void Update(sf::RenderWindow* = 0);
};

#endif // MAP_H
