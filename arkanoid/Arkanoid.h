#ifndef ARKANOID_H_INCLUDED
#define ARKANOID_H_INCLUDED

#define BLUE makecol(0,0,255)
#define BLACK makecol(0,0,0)
#define CYAN makecol(0,255,255)
#define PINK makecol (192, 192, 255)
#define WHITE makecol(255,255,255)

#include <allegro.h>

struct Myfont
{
    FONT *myfont;
}f;

extern void initialise_alleg(void);
extern void create_menu(void);

#endif
