#include "map.h"

Map::Map() {
    m_background.loadFromFile("SpaceBackground.png");

    m_planets.append(new Planet("Planet1.png", sf::Vector2<float>(0,0), 0.01, 1));
    m_planets.append(new Planet("Planet1.png", sf::Vector2<float>(550,880), -0.03, 1));
}

void Map::Draw(sf::RenderWindow * window) {
    sf::Sprite background;
    background.setTexture(m_background);
    window->draw(background);

    foreach(Planet* planet, m_planets) {
        planet->Draw(window);
    }
}

void Map::Update(sf::RenderWindow * window) {
    foreach(Planet* planet, m_planets) {
        planet->Update(window);
    }
}
