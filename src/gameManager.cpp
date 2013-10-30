#include "gameManager.h"

gameManager::gameManager()
{
    setGameState(LOADING);

    if (!listFont.loadFromFile("TIFAX.ttf"))
    {
        qDebug() << "Font file not loaded";
    }

}
//in order to draw we must pass in the display object
void gameManager::Draw(sf::RenderWindow *window) {
    window->clear(sf::Color::Cyan);

    switch(getGameState()) {
        case LOADING:

        break;
        case MENU:
            m_mainMenu->Draw(window);
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
void gameManager::Update(sf::RenderWindow* window) {
    switch(getGameState()) {
        case LOADING:
            qDebug("--Loading state--");

            //Maim Menu Setup
            m_mainMenu = new Menu(ScreenWidth/3,300, listFont);

            m_mainMenu->AddItem("Play", GAME);
            m_mainMenu->AddItem("About", ABOUT);
            m_mainMenu->AddItem("Exit", CLOSE);
            m_mainMenu->SetSpacing(90);

            setGameState(MENU);
        break;
        case MENU: {
            int state = m_mainMenu->Update(window);

            setGameState(state == -1 ? MENU : state);
            //qDebug("--Menu state--");
        }
        break;
        case ABOUT:
            qDebug("--About state--");
        break;
        case GAME:
            qDebug("--Game state--");
        break;
        case CLOSE:
            qDebug("--Quiting--");
            window->close();
        break;
    }
}

int gameManager::getGameState() {
    return m_gameState;
}

void gameManager::setGameState(int state) {
    m_gameState = state;
}
