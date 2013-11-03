#include "player.h"

Player::Player() {
    qDebug() << "Player init";
    m_vel = sf::Vector2<float>(5,0);
    m_pos = sf::Vector2<float>(400, 300);

    m_rotation = 0;

    if (!m_texture.loadFromFile("Ship.png"))
    {
        // error...
    }
    m_texture.setSmooth(true);
}

void Player::Draw(sf::RenderWindow* window) {
    sf::Sprite sprite;
    sf::Vector2u size = m_texture.getSize();
    sprite.setTexture(m_texture);
    sprite.setPosition(m_pos.x - size.x/2, m_pos.y - size.y/2);
    sprite.setRotation((m_rotation * RAD_TO_DEG) + 90);
    sprite.setOrigin(size.x/2,size.y/2);
    sf::CircleShape player(25);
    player.setPosition(m_pos.x, m_pos.y);


    window->draw(sprite);
}

void Player::Update(sf::RenderWindow* window) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_rotation -= 0.1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_rotation += 0.1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        thrustFoward();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        //thrustReverse();
    }

    m_pos += m_vel;
}

void Player::addVelocityVector(sf::Vector2<float> vel) {
    m_vel += vel;
}

void Player::thrustFoward()
{
    m_vel += sf::Vector2<float>(qCos(m_rotation)*m_thrust, qSin(m_rotation) * m_thrust);
}

void Player::thrustReverse()
{
    m_vel -= sf::Vector2<float>(qCos(m_rotation)*m_thrust, qSin(m_rotation) * m_thrust);
}
