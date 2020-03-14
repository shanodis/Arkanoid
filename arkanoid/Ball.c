#include "Game.h"
#include <time.h>

void start_position_of_ball(struct Ball *b)
{
    b->dx=b->dy=0.5f;
    b->x=SCREEN_W/2-10;
    b->y=SCREEN_H-62; /*62-to bedzie "y" na kolizje z paletka*/
}

void ball_movement(struct Ball *b)
{
    b->x+=b->dx;
    b->y+=b->dy;

    if(b->x<=1 || b->x>=SCREEN_W-20)     b->dx *= -1;
    if(b->y <=0 || b->y>=SCREEN_H-60)    b->dy *= -1;
}

void collision_with_paddle(struct Ball *b,struct Paddle *p)
{
    srand(time(0));
    if(b->x>=p->Colx1 && b->x<=p->Colx2 && b->y==SCREEN_H-62)
        allegro_message("Udalo sie!");
}
