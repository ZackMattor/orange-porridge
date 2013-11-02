#ifndef PLANET_H
#define PLANET_H

#include <SFML/Graphics.hpp>

#include <QDebug>
#include <QString>
#include <QList>

#include "entity.h"
#include "globals.h"

class Planet : public Entity
{
public:
    Planet(QString imagePath, sf::Vector2<float> location, float rotationVelocity, float mass);

    void Draw(sf::RenderWindow*);
    void Update(sf::RenderWindow* = 0);

    void setMass(float);
    void setRotationVelocity(float);

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    double m_rotationVelocity;
    float m_mass;
};

#endif // PLANET_H
