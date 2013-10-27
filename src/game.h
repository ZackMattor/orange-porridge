#ifndef GAME_H
#define GAME_H

#include "globals.h"

class game
{
public:
    game();

    //in order to draw we must pass in the display object
    void Draw();

    //inject mouse and keyboard through the update function
    void Update();

    int getGameState();
    void setGameState(int);
private:
    int m_gameState;

};

#endif // GAME_H
