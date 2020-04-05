#include "Arkanoid.h"
#include <allegro.h>

extern int go_down(int count,int *c1,int *c2,int *c3);
extern int go_up(int count,int *c1,int *c2,int *c3);

static void load_myfont(struct Myfont *f)
{
    f->myfont=load_font("data/font3.pcx",NULL,NULL);
}

static void move_in_menu(BITMAP *Logo,struct Myfont f)
{
    int count=1;
    int choose_colour1=PINK,choose_colour2=WHITE,choose_colour3=WHITE;

    while(!key[KEY_ESC])
    {
        if(key[KEY_DOWN])
        {
            count=go_down(count,&choose_colour1,&choose_colour2,&choose_colour3);
            rest(150);
        }
        if(key[KEY_UP])
        {
            count=go_up(count,&choose_colour1,&choose_colour2,&choose_colour3);
            rest(150);
        }
        if(key[KEY_ENTER] && count==3) exit(0);
        if(key[KEY_ENTER] && count==1)
        {
            destroy_bitmap(Logo);
            clear_bitmap(screen);
            clear_to_color(screen,WHITE);
            break;
        }

        draw_sprite(screen,Logo,200,50);
        textout_centre_ex(screen,f.myfont,"Start game",SCREEN_W/2,SCREEN_H/2,BLACK,choose_colour1);
        textout_centre_ex(screen,f.myfont,"Credits",SCREEN_W/2,SCREEN_H-220,BLACK,choose_colour2);
        textout_centre_ex(screen,f.myfont,"Quit game",SCREEN_W/2,SCREEN_H-140,BLACK,choose_colour3);
    }
    if(key[KEY_ESC])
        exit(0);
}

void create_menu(void)
{
    load_myfont(&f);
    if(!f.myfont)
        allegro_message(allegro_error);

    BITMAP *Logo=load_bitmap("data/MainLogo.bmp",NULL);
    clear_to_color(screen,WHITE);

    move_in_menu(Logo,f);
}
