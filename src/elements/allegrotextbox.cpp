#include "allegrotextbox.h"

AllegroTextBox::AllegroTextBox(int x, int y, int Width, int Height, ALLEGRO_FONT* Font)
  : m_hasFocus(false)
  , m_value("")
  , m_passwordMode(false)
  , m_xPos(x)
  , m_yPos(y)
  , m_width(Width)
  , m_height(Height)
  , m_boxFont(Font)
{
    m_backgroundColor = al_map_rgb(0,0,0);
    m_defaultBorder = al_map_rgb(255,255,255);
    m_focusedBorder = al_map_rgb(69,214,95);
    m_textColor = al_map_rgb(69,214,95);
    m_sidePadding = 10;
}

void AllegroTextBox::Draw()
{
    int bbx;
    int bby;
    int bbw;
    int bbh;

    QString display = m_value;

    if (m_passwordMode)
        display.fill('*');

    al_get_text_dimensions(m_boxFont, display.toStdString().c_str(), &bbx, &bby, &bbw, &bbh);

    int x1 = GetXPos();
    int y1 = GetYPos();
    int x2 = x1 + GetWidth();
    int y2 = y1 + GetHeight();

    al_draw_filled_rectangle(x1, y1, x2, y2, m_backgroundColor);
    al_draw_rectangle(x1, y1, x2, y2, GetFocus() ? m_focusedBorder : m_defaultBorder, 1);

    bool Overflow = (bbw > GetWidth() - m_sidePadding * 2);

    al_set_clipping_rectangle((m_xPos+m_sidePadding), m_yPos, (GetWidth()-m_sidePadding*2), GetHeight());
    al_draw_text(m_boxFont, m_textColor, Overflow ? (m_xPos+GetWidth()-m_sidePadding) : (m_xPos+m_sidePadding), (m_yPos + (GetHeight() / 2) - bbh/2), Overflow ? ALLEGRO_ALIGN_RIGHT : ALLEGRO_ALIGN_LEFT, display.toStdString().c_str());
    al_reset_clipping_rectangle();
}

void AllegroTextBox::Update(bool curKeys[255], ALLEGRO_MOUSE_EVENT *mouse)
{

    if(mouse->button & 1)
    {
        SetFocus(false);

        if(mouse->x > m_xPos && mouse->x < m_xPos + GetWidth())
        {
            if(mouse->y > m_yPos && mouse->y < m_yPos + GetHeight())
            {
                SetFocus(true);
            }
        }
    }

    if(m_hasFocus)
    {
        char Letter = GetKeyPressed(curKeys);

        if(Letter == 1)
        {
            m_value.truncate(m_value.size() -1);
        }
        else if(Letter != 0)
        {
            m_value += Letter;
        }
    }
}

//Get functions
QString AllegroTextBox::GetValue()
{
    return m_value;
}

int AllegroTextBox::GetXPos()
{
    return m_xPos;
}

int AllegroTextBox::GetYPos()
{
    return m_yPos;
}

int AllegroTextBox::GetWidth()
{
    return m_width;
}

int AllegroTextBox::GetHeight()
{
    return m_height;
}

bool AllegroTextBox::GetFocus()
{
    return m_hasFocus;
}

bool AllegroTextBox::IsPasswordMode()
{
    return m_passwordMode;
}

ALLEGRO_FONT* AllegroTextBox::GetFont()
{
    return m_boxFont;
}

ALLEGRO_COLOR AllegroTextBox::GetTextColor()
{
    return m_textColor;
}

ALLEGRO_COLOR AllegroTextBox::GetFocusColor()
{
    return m_focusedBorder;
}

ALLEGRO_COLOR AllegroTextBox::GetBackgroundColor()
{
    return m_backgroundColor;
}

ALLEGRO_COLOR AllegroTextBox::GetDefaultColor()
{
    return m_defaultBorder;
}

//Set functions
void AllegroTextBox::SetPos(int x, int y)
{
    m_xPos = x;
    m_yPos = y;
}

void AllegroTextBox::SetSize(int Width, int Height)
{
    m_width = Width;
    m_height = Height;
}

void AllegroTextBox::SetValue(QString Value)
{
    m_value = Value;
}

void AllegroTextBox::SetFocus(bool HasFocus)
{
    m_hasFocus = HasFocus;
}

void AllegroTextBox::SetFont(ALLEGRO_FONT* Font)
{
    m_boxFont = Font;
}

void AllegroTextBox::SetTextColor(ALLEGRO_COLOR color)
{
    m_textColor = color;
}

void AllegroTextBox::SetBackgroundColor(ALLEGRO_COLOR color)
{
    m_backgroundColor = color;
}

void AllegroTextBox::SetFocusColor(ALLEGRO_COLOR color)
{
    m_focusedBorder = color;
}

void AllegroTextBox::SetDefaultColor(ALLEGRO_COLOR color)
{
    m_defaultBorder = color;
}

char AllegroTextBox::GetKeyPressed(bool curKeys[255])
{
    char Letter = 0;

    for(int i = 0; i < 37; i++) //Letters & Numbers
    {
        if(!m_prevKeys[i] && curKeys[i])
        {
            if(i < 27) //We are a letter
            {
                Letter = ((curKeys[ALLEGRO_KEY_RSHIFT] || curKeys[ALLEGRO_KEY_LSHIFT]) ? (char)(i+64) : (char)(i+96));
            }
            else if(!curKeys[ALLEGRO_KEY_RSHIFT] && !curKeys[ALLEGRO_KEY_LSHIFT]) //We are a number
            {
                Letter = (char)(i+21);
            }
            break;
        }
    }

    Letter = ((!m_prevKeys[ALLEGRO_KEY_SPACE] && curKeys[ALLEGRO_KEY_SPACE]) ? ' ' : Letter);

    Letter = ((!m_prevKeys[ALLEGRO_KEY_BACKSPACE] && curKeys[ALLEGRO_KEY_BACKSPACE]) ? 1 : Letter);

    for(int i = 0; i < 255; i++) //Set m_prevKeys
    {
        m_prevKeys[i] = curKeys[i];
    }

    return Letter;
}

void AllegroTextBox::SetPasswordMode(bool enabled)
{
    m_passwordMode = enabled;
}
