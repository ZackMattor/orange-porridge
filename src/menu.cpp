#include "menu.h"

#include <QtCore/QStringList>

#include "elements/allegrobutton.h"

#define BUTTON_HEIGHT 40

Menu::Menu(int x, int y, ALLEGRO_FONT *font)
    : m_xPos(x)
    , m_yPos(y)
    , m_spacing(10)
    , m_font(font)
{
}

void Menu::SetSpacing(int Gap)
{
    if(Gap >= 0)
    {
        m_spacing = Gap;
    }
}

int Menu::Update(bool keys[], ALLEGRO_MOUSE_EVENT *mouse)
{
    Q_UNUSED(keys);
    int gameState = -1;

    foreach(const menuItem &i, m_menuItems)
    {
        if (i.button->Update(mouse))
        {
            gameState = i.value;
            break;
        }
    }
    return gameState;
}

void Menu::Draw()
{
    //al_draw_text(m_font, al_map_rgb(69,214,95), m_xPos + 130, 20, ALLEGRO_ALIGN_CENTRE, "Triangles in Space");
    foreach(const menuItem &i, m_menuItems)
    {
        i.button->Draw();
    }
}

void Menu::AddItem(QString Title, int Value)
{
    menuItem newItem;
    int X = m_xPos;
    int Y = 100 + (m_menuItems.size() * BUTTON_HEIGHT) + (m_menuItems.size() * m_spacing);
    newItem.button = new AllegroButton(X, Y, BUTTON_HEIGHT, 222, m_font, al_map_rgb(0,0,0), al_map_rgb(40,40,40), Title);
    newItem.value = Value;

    m_menuItems << newItem;
}
