#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>

#include <QDebug>

#include "globals.h"
#include "game/game.h"
#include "menu.h"

class gameManager
{
public:
    gameManager();

    //in order to draw we must pass in the display object
    void Draw(sf::RenderWindow*);

    //inject mouse and keyboard through the update function
    void Update(sf::RenderWindow*);

    int getGameState();
    void setGameState(int);
private:
    bool isFirstInState();


    bool m_firstInState;
    int m_gameState;

    sf::View *m_camera;
    sf::Font listFont;

    Menu *m_mainMenu;
    Game *m_game;
};

#endif // GAMEMANAGER_H
