#include "game.h"

Game::Game() {
    m_player = new Player();
    m_map = new Map();
}

void Game::draw(sf::RenderWindow * window) {
    drawBackground(window);
    m_map->Draw(window);
    m_player->Draw(window);

}

void Game::update(sf::View *camera, sf::RenderWindow * window) {
    m_map->Update();

    m_player->addVelocityVector(m_map->getGravityOnPoint(m_player->getPosition(), 1));

    m_player->Update();
    camera->setCenter(m_player->getPosition().x, m_player->getPosition().y);
}

void Game::drawBackground(sf::RenderWindow* window) {
    sf::Sprite background;
    sf::Texture *backTexture = m_map->getBackground();
    sf::Vector2u backgroundSize = backTexture->getSize();
    background.setTexture(*backTexture);

    sf::Vector2i playerBackgroundPosition = sf::Vector2i(floor(m_player->getPosition().x/backgroundSize.x), floor(m_player->getPosition().y/backgroundSize.y));

    int i, j;

    sf::Vector2i backgroundOnMap = sf::Vector2i(ceil(ScreenWidth / backgroundSize.x)+1, ceil(ScreenWidth / backgroundSize.y)+1);

    for(i = -1; i <= backgroundOnMap.y; i++) {
        for(j = -1; j <= backgroundOnMap.x; j++) {
            background.setPosition((floor(m_player->getPosition().x/backgroundSize.x)+j)*(int)backgroundSize.x, (floor(m_player->getPosition().y/backgroundSize.y)+i)*(int)backgroundSize.y);
            //background.setPosition(((m_player->getPosition().x/2/backgroundSize.x)+(j*(int)backgroundSize.x))*(int)backgroundSize.x, (floor(m_player->getPosition().y/backgroundSize.y)+i)*(int)backgroundSize.y);
            window->draw(background);
        }
    }

    //background.setPosition(m_player->getPosition().x/2, m_player->getPosition().y/2);
    //window->draw(background);
}
