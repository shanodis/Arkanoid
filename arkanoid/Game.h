#ifndef PADDLE_H_INCLUDED
#define PADDLE_H_INCLUDED

#include <allegro.h>

struct Paddle
{
    double x,y;
    double Colx1,Coly1,Colx2,Coly2;
    BITMAP *paddle;

}p;

struct Bufor
{
    BITMAP *bufor;

}buf;

extern void start_game(void);
extern void course_of_the_game(void);
extern void load_files(void);

extern void start_position_of_paddle(struct Paddle *);
extern void start_position_of_collider(struct Paddle *p);
extern void move_paddle(struct Paddle *);

#endif
