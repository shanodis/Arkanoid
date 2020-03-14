#include "Game.h"
#include "Arkanoid.h"

void start_position_of_paddle(struct Paddle *p)
{
    p->x=SCREEN_W/2-50;
    p->y=SCREEN_H-40;
}

void move_paddle(struct Paddle *p)
{
    if(key[KEY_LEFT] && p->x>=1)
    {
        p->x=p->x-1.5;
        p->Colx1=p->Colx1-1.5;
        p->Colx2=p->Colx2-1.5;
    }

    if(key[KEY_RIGHT] && p->x<=SCREEN_W-103)
    {
        p->x=p->x+1.5;
        p->Colx1=p->Colx1+1.5;
        p->Colx2=p->Colx2+1.5;
    }
}

void start_position_of_collider(struct Paddle *p)
{
    p->Colx1=SCREEN_W/2-50;
    p->Coly1=SCREEN_H-40;

    p->Colx2=SCREEN_W/2+54;
    p->Coly2=SCREEN_H-40+24;
}

void create_paddle_collider(struct Paddle p,struct Bufor b)
{
    rectfill(buf.bufor,p.Colx1,p.Coly1,p.Colx2,p.Coly2,BLACK);
}
