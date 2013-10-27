#include "gameManager.h"

gameManager::gameManager()
{
    setGameState(LOADING);
}
//in order to draw we must pass in the display object
void gameManager::Draw() {
    switch(getGameState()) {
    case LOADING:

    break;
    case MENU:
    break;
    case ABOUT:
    break;
    case GAME:
    break;
    case CLOSE:
    break;

    }
}

//inject mouse and keyboard through the update function
void gameManager::Update() {
    switch(getGameState()) {
        case LOADING:
            qDebug("--Loading state--");
            setGameState(MENU);
        break;
        case MENU:
            qDebug("--Menu state--");
        break;
        case ABOUT:
            qDebug("--About state--");
        break;
        case GAME:
            qDebug("--Game state--");
        break;
        case CLOSE:
            qDebug("--Quiting--");
        break;
    }
}

int gameManager::getGameState() {
    return m_gameState;
}

void gameManager::setGameState(int state) {
    m_gameState = state;
}
