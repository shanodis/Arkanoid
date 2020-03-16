#include "Game.h"
#include "Ball.h"

#include <math.h>

void start_position_of_ball(struct Ball *b)
{
    b->speed=0.6f;

    b->dx=cos(60 * 22/7)*b->speed;
    b->dy=sin(60 * 22/7)*b->speed;

    b->x=SCREEN_W/2-10;
    b->y=SCREEN_H-72; /*62-to bedzie "y" na kolizje z paletka*/
}

void ball_movement(struct Ball *b)
{
    b->x+=b->dx;
    b->y+=b->dy;

    if(b->x<=1 || b->x>=SCREEN_W-20)
    {
        b->dx *= -1;
    }
    if(b->y <=0)
    {
        b->dy *= -1;
    }
}

int collision_with_paddle(struct Ball *b,struct Paddle *p)
{
    int score;

    if(b->x>=p->Colx1 && b->x<=p->Colx2 && b->y>=SCREEN_H-64)
    {
        b->dy *= -1;
    }
    if(b->y>=SCREEN_H-20)
        start_game();

    return score;
}
