#include "map.h"

Map::Map() {
    m_background.loadFromFile("SpaceBackground.png");
    m_planet.loadFromFile("Planet1.png");
    m_planet.setSmooth(true);
    m_planetRotation = 0;
}

void Map::Draw(sf::RenderWindow * window) {
    sf::Sprite background;
    background.setTexture(m_background);
    window->draw(background);

    sf::Sprite planet;
    planet.setTexture(m_planet);
    planet.setRotation(m_planetRotation);
    sf::Vector2u planetSize = m_planet.getSize();
    planet.setOrigin(planetSize.x/2, planetSize.y/2);
    planet.setPosition(400,300);
    window->draw(planet);
}

void Map::Update(sf::RenderWindow * window) {
    m_planetRotation += 0.05;
}
