#ifndef STARFIELD_H
#define STARFIELD_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <QtCore/QTime>
#include "globals.h"

class Starfield {
public:
    static ALLEGRO_BITMAP *makeStarfield(int numStars, ALLEGRO_DISPLAY *display);

};

#endif
