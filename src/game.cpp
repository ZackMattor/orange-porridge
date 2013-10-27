#include "game.h"

game::game()
{
    setGameState(LOADING);
}
//in order to draw we must pass in the display object
void game::Draw() {

}

//inject mouse and keyboard through the update function
void game::Update() {

}

int game::getGameState() {
    return m_gameState;
}

void game::setGameState(int state) {
    m_gameState = state;
}
