#ifndef MENU_H
#define MENU_H

#include <QList>
#include <QString>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "globals.h"

class AllegroButton;

class Menu
{
public:
    Menu(int x, int y, ALLEGRO_FONT *font);
    void AddItem(QString Title, int Value);
    void SetSpacing(int Gap);

    int Update(bool keys[], ALLEGRO_MOUSE_EVENT *mouse);

    void Draw();
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
    ALLEGRO_FONT *m_font;
    ALLEGRO_BITMAP *background;
};

#endif // MENU_H
