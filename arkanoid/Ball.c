#include "Game.h"
#include "Ball.h"
#include <math.h>
#include <time.h>

void start_position_of_ball(struct Ball *b)
{
    b->speed=0.6f;

    b->dx=cos(90 * 22/7)*b->speed;
    b->dy=sin(90 * 22/7)*b->speed;

    b->x=SCREEN_W/2-10; /*dla obrazka*/
    b->y=SCREEN_H-72; /*dla obrazka*/
}

void set_new_direction(struct Ball *b)
{
    srand(time(NULL));
    int angle,dir=rand()%2;

    if(dir==0)
        angle=230+rand()%30;
    else
        angle=310-rand()%30;

    b->dx=cos(angle * 3.141592 / 180)*b->speed;
    b->dy=sin(angle * 3.141592 / 180)*b->speed;
}

void ball_movement(struct Ball *b)
{
    b->x+=b->dx;/*dla obrazka*/
    b->y+=b->dy;/*dla obrazka*/

    b->x1+=b->dx;/*dla kolidera*/
    b->x2+=b->dx;/*dla kolidera*/
    b->y1+=b->dy;/*dla kolidera*/
    b->y2+=b->dy;/*dla kolidera*/

    if(b->x + b->radius<=20 || b->x + b->radius>=SCREEN_W-5)
        b->dx *= -1;

    if(b->y + b->radius<=20)
        b->dy *= -1;
}
