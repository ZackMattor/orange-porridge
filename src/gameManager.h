#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>

#include <QDebug>

#include "globals.h"
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
    int m_gameState;

    sf::Font listFont;
    Menu *m_mainMenu;
};

#endif // GAMEMANAGER_H
