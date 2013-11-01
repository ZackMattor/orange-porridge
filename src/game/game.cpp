#include "game.h"

Game::Game() {
    m_player = new Player();
    m_map = new Map();
}

void Game::draw(sf::RenderWindow * window) {
    m_map->Draw(window);
    m_player->Draw(window);
}

void Game::update(sf::View *camera, sf::RenderWindow * window) {
    sf::Vector2<double> playerPos = m_player->getPlayerPosition();
    camera->setCenter(playerPos.x, playerPos.y);
    m_map->Update();
    m_player->Update();
}
