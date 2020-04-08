#ifndef ARKANOID_H_INCLUDED
#define ARKANOID_H_INCLUDED

#include <allegro.h>
#define BLUE makecol(0,0,255)
#define BLACK makecol(0,0,0)
#define CYAN makecol(0,255,255)
#define PINK makecol (192, 192, 255)
#define WHITE makecol(255,255,255)


struct Myfont
{
    FONT *myfont;
};

extern void initialise_alleg(void);
extern void create_menu(void);
extern void load_myfont(struct Myfont *);

#endif
