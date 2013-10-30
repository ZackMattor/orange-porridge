#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#include <QList>
#include <QString>

#include "globals.h"

class AllegroButton;

class Menu
{
public:
    Menu(int x, int y, sf::Font font);
    void AddItem(QString Title, int Value);
    void SetSpacing(int Gap);

    int Update(sf::RenderWindow*);

    void Draw(sf::RenderWindow*);
private:
    struct menuItem
    {
        AllegroButton *button;
        int value;
    };

    QList<menuItem> m_menuItems;

    double m_gameTime;
    int m_xPos, m_yPos;
    int m_spacing;
    sf::Font m_font;
    //ALLEGRO_BITMAP *background;
};

#endif // MENU_H
