#include "planet.h"

Planet::Planet(QString imagePath, sf::Vector2<float> location, float rotationVelocity, float mass) {
    setMass(mass);
    setRotationVelocity(rotationVelocity);

    m_rotation = 0;
    m_pos = location;

    m_texture.loadFromFile(imagePath.toStdString());
    m_texture.setSmooth(true);

    m_sprite.setTexture(m_texture);
}

void Planet::setMass(float mass) {
    if(mass > 0) {
        m_mass = mass;
    }
}

void Planet::setRotationVelocity(float rotationVelocity) {
    m_rotationVelocity = rotationVelocity;
}

void Planet::Update(sf::RenderWindow *window) {
    m_rotation += m_rotationVelocity;
}

void Planet::Draw(sf::RenderWindow *window) {
    sf::Vector2u planetSize = m_texture.getSize();
    m_sprite.setOrigin(planetSize.x/2, planetSize.y/2);
    m_sprite.setPosition(m_pos.x, m_pos.y);
    m_sprite.setRotation(m_rotation * RAD_TO_DEG);
    window->draw(m_sprite);
}
