#include "player.h"

Player::Player() {
    m_vel = sf::Vector2<double>(0,0);
    m_pos = sf::Vector2<double>(400, 300);
}

void Player::Draw(sf::RenderWindow* window) {
    sf::CircleShape player(25);
    player.setPosition(m_pos.x, m_pos.y);

    window->draw(player);
}

void Player::Update(sf::RenderWindow* window) {
    m_pos += m_vel;
}
