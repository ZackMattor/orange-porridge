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
    m_map->Update();
    m_player->Update();
    camera->setCenter(m_player->getPlayerPosition().x, m_player->getPlayerPosition().y);
}
