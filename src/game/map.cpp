#include "map.h"
#include <QtCore/qmath.h>
Map::Map() {
    m_background.loadFromFile("SpaceBackground.png");

    m_planets.append(new Planet("Planet1.png", sf::Vector2<float>(400,500), 0.01, 1));
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

sf::Vector2<float> Map::getGravityOnPoint(sf::Vector2<float> pos, float mass) {
    float xd, yd, d2, xf, yf, xv, yv;
    sf::Vector2<float> resultVelocity(0,0);
    foreach(Planet* planet, m_planets) {
        xd = pos.x-planet->getPosition().x;
        yd = pos.y-planet->getPosition().y;
        d2 = xd*xd+yd*yd;
        xf = xd/d2;
        yf = yd/d2;
        resultVelocity -= sf::Vector2<float>(xf*17,yf*17);
    }

    return resultVelocity;
}
