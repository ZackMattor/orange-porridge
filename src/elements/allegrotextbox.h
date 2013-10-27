#ifndef ALLEGROTEXTBOX_H
#define ALLEGROTEXTBOX_H

#include <QString>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

class AllegroTextBox
{
public:
    AllegroTextBox(int x, int y, int Width, int Height, ALLEGRO_FONT* Font);

    void Draw();
    void Update(bool curKeys[255], ALLEGRO_MOUSE_EVENT *mouse);

    //Get functions
    QString GetValue();
    int GetXPos();
    int GetYPos();
    int GetWidth();
    int GetHeight();
    bool GetFocus();
    bool IsPasswordMode();

    ALLEGRO_FONT* GetFont();
    ALLEGRO_COLOR GetTextColor();
    ALLEGRO_COLOR GetBackgroundColor();
    ALLEGRO_COLOR GetFocusColor();
    ALLEGRO_COLOR GetDefaultColor();

    //Set functions
    void SetPos(int x, int y);
    void SetSize(int Width, int Height);
    void SetValue(QString Value);
    void SetFocus(bool Value);
    void SetFont(ALLEGRO_FONT *Font);
    void SetTextColor(ALLEGRO_COLOR color);
    void SetBackgroundColor(ALLEGRO_COLOR color);
    void SetFocusColor(ALLEGRO_COLOR color);
    void SetDefaultColor(ALLEGRO_COLOR color);
    void SetPasswordMode(bool enabled);

private:

    char GetKeyPressed(bool curKeys[255]);

    //Box active members
    bool m_hasFocus;
    QString m_value;
    bool m_prevKeys[255];
    bool m_passwordMode;

    //Location and Dimensions
    int m_xPos, m_yPos;
    int m_width, m_height;
    int m_sidePadding;

    //Font
    ALLEGRO_FONT *m_boxFont;

    //Colors
    ALLEGRO_COLOR m_textColor;
    ALLEGRO_COLOR m_backgroundColor;
    ALLEGRO_COLOR m_focusedBorder;
    ALLEGRO_COLOR m_defaultBorder;
};

#endif // ALLEGROTEXTBOX_H
