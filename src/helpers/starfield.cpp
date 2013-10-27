
#include "starfield.h"

ALLEGRO_BITMAP * Starfield::makeStarfield(int numStars, ALLEGRO_DISPLAY *display) {
    ALLEGRO_BITMAP * bit = al_create_bitmap(ScreenWidth, ScreenHeight);

    al_set_target_bitmap(bit);

    //al_clear_to_color(al_map_rgb(0, 0, 0));

    int i;
    for(i = 0; i < numStars; i++) {
        al_put_pixel(qrand() % ScreenWidth, qrand() % ScreenHeight, al_map_rgb(255,255,255));
    }

    al_set_target_bitmap(al_get_backbuffer(display));

    return bit;
}
