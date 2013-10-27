#ifndef ALLEGROBUTTON_H
#define ALLEGROBUTTON_H

#include <QtCore/QString>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

class AllegroButton
{
    private:
        QString m_Text;
        int m_xPos, m_yPos;
        int m_Height, m_Width;
        bool m_Active;

        qint8 m_prevClick;

        ALLEGRO_FONT *m_buttonFont;
        ALLEGRO_COLOR m_inactiveColor, m_activeColor, m_textColor, m_borderColor;
    public:
        AllegroButton(int X, int Y, int Height, int Width, ALLEGRO_FONT *ButtonFont, ALLEGRO_COLOR InactiveColor = al_map_rgb(204,204,0), ALLEGRO_COLOR ActiveColor = al_map_rgb(204,204,204), QString Text = "Button");

        bool Update(ALLEGRO_MOUSE_EVENT *mouse);
        void Draw();
};

#endif // ALLEGROBUTTON_H
