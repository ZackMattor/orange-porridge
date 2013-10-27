#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "globals.h"
#include <QDebug>

class gameManager
{
public:
    gameManager();

    //in order to draw we must pass in the display object
    void Draw();

    //inject mouse and keyboard through the update function
    void Update();

    int getGameState();
    void setGameState(int);
private:
    int m_gameState;

};

#endif // GAMEMANAGER_H
