#include "allegrobutton.h"

using namespace std;

AllegroButton::AllegroButton(int X, int Y, int Height, int Width, sf::Font ButtonFont, sf::Color InactiveColor, sf::Color ActiveColor, QString Text)
{
    m_Text = Text;
    m_xPos = X;
    m_yPos = Y;
    m_Height = Height;
    m_Width = Width;
    m_buttonFont = ButtonFont;
    m_inactiveColor = InactiveColor;
    m_activeColor = ActiveColor;

    m_textColor = sf::Color(255,255,255);
    m_borderColor = sf::Color(69,214,95);

    m_prevClick = 0;
    m_Active = false;
}

bool AllegroButton::Update(sf::RenderWindow* window)
{

    sf::Vector2i localPosition = sf::Mouse::getPosition(*window); // window is a sf::Window
    m_Active = false;

    if(localPosition.x > m_xPos && localPosition.x < m_xPos + m_Width)
    {
        if(localPosition.y > m_yPos && localPosition.y < m_yPos + m_Height)
        {
            m_Active = true;

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {

                if(m_prevClick == 1)
                {
                    qDebug() << "asdf";
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

void AllegroButton::Draw(sf::RenderWindow* window)
{
    //al_get_text_dimensions(m_buttonFont, m_Text.toStdString().c_str(), &bbx, &bby, &bbw, &bbh);

    sf::RectangleShape button(sf::Vector2f(m_Width, m_Height));
    button.setOutlineThickness(1);
    button.setFillColor((m_Active ?  m_activeColor : sf::Color::Blue));
    button.setOutlineColor(m_borderColor);

    button.setPosition(m_xPos, m_yPos);
    sf::Vector2f buttonSize = button.getSize();
    window->draw(button);

    sf::Text buttonText(m_Text.toStdString(), m_buttonFont, 25);
    buttonText.setColor(m_textColor);
    sf::FloatRect textBounds = buttonText.getGlobalBounds();

    buttonText.setPosition(m_xPos + (buttonSize.x - textBounds.width)/2, m_yPos + (buttonSize.y - textBounds.height)/2);
    window->draw(buttonText);
    //al_draw_filled_rectangle(m_xPos, m_yPos, m_xPos + m_Width,  m_yPos + m_Height , (m_Active ?  m_activeColor : m_inactiveColor));
    //al_draw_rectangle(m_xPos, m_yPos, m_xPos + m_Width,  m_yPos + m_Height, m_borderColor, 1);
    //al_draw_text(m_buttonFont, m_textColor, m_xPos+20, (m_yPos + (m_Height / 2) - bbh/2), ALLEGRO_ALIGN_LEFT, m_Text.toStdString().c_str());
}
