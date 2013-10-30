#ifndef ALLEGROBUTTON_H
#define ALLEGROBUTTON_H

#include <SFML/Graphics.hpp>
#include <QtCore/QString>
#include <QDebug>

class AllegroButton
{
    private:
        QString m_Text;
        int m_xPos, m_yPos;
        int m_Height, m_Width;
        bool m_Active;

        qint8 m_prevClick;

        sf::Font m_buttonFont;
        sf::Color m_inactiveColor, m_activeColor, m_textColor, m_borderColor;
    public:
        AllegroButton(int X, int Y, int Height, int Width, sf::Font ButtonFont, sf::Color InactiveColor = sf::Color(204,204,0), sf::Color ActiveColor = sf::Color(204,204,204), QString Text = "Button");

        bool Update(sf::RenderWindow*);
        void Draw(sf::RenderWindow*);
};

#endif // ALLEGROBUTTON_H
