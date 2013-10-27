#include "allegrobutton.h"
#include <iostream>

using namespace std;

AllegroButton::AllegroButton(int X, int Y, int Height, int Width, ALLEGRO_FONT *ButtonFont, ALLEGRO_COLOR InactiveColor, ALLEGRO_COLOR ActiveColor, QString Text)
{
    m_Text = Text;
    m_xPos = X;
    m_yPos = Y;
    m_Height = Height;
    m_Width = Width;
    m_buttonFont = ButtonFont;
    m_inactiveColor = InactiveColor;
    m_activeColor = ActiveColor;

    m_textColor = al_map_rgb(255,255,255);
    m_borderColor = al_map_rgb(69,214,95);

    m_prevClick = 0;
    m_Active = false;
}

bool AllegroButton::Update(ALLEGRO_MOUSE_EVENT *mouse)
{
    m_Active = false;

    if(mouse->x > m_xPos && mouse->x < m_xPos + m_Width)
    {
        if(mouse->y > m_yPos && mouse->y < m_yPos + m_Height)
        {
            m_Active = true;

            if(mouse->button & 1)
            {
                if(m_prevClick == 1)
                {
                    m_prevClick = 2;
                    return true;
                }
            } else
            {
                m_prevClick = 1;
            }
        }
    }

    return false;
}

void AllegroButton::Draw()
{
    int bbx;
    int bby;
    int bbw;
    int bbh;

    al_get_text_dimensions(m_buttonFont, m_Text.toStdString().c_str(), &bbx, &bby, &bbw, &bbh);


    al_draw_filled_rectangle(m_xPos, m_yPos, m_xPos + m_Width,  m_yPos + m_Height , (m_Active ?  m_activeColor : m_inactiveColor));
    al_draw_rectangle(m_xPos, m_yPos, m_xPos + m_Width,  m_yPos + m_Height, m_borderColor, 1);
    al_draw_text(m_buttonFont, m_textColor, m_xPos+20, (m_yPos + (m_Height / 2) - bbh/2), ALLEGRO_ALIGN_LEFT, m_Text.toStdString().c_str());
}
