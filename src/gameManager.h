#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "globals.h"
#include "menu.h"
#include <QDebug>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

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
    ALLEGRO_FONT *listFont;
    Menu *m_mainMenu;
};

#endif // GAMEMANAGER_H
