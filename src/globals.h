#ifndef GLOBALS_H
#define GLOBALS_H
#define _USE_MATH_DEFINES
#include <math.h>

#define RAD_TO_DEG 180/M_PI
#define DEG_TO_RAD M_PI/180

enum STATE{LOADING, MENU, ABOUT, GAME, CLOSE};

const int ScreenHeight = 600;
const int ScreenWidth = 800;

static int TICS_PER_SEC = 60;
static int FRAMES_PER_SEC = 60;

#endif // GLOBALS_H
