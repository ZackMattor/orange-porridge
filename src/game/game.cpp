#include "game.h"

Game::Game() {
    m_player = new Player();
}

void Game::draw(sf::RenderWindow * window) {
    m_player->Draw(window);
}

void Game::update(sf::RenderWindow * window) {
    m_player->Update();
}
