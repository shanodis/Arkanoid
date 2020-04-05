#ifndef PADDLE_H_INCLUDED
#define PADDLE_H_INCLUDED

#include <allegro.h>
#include <stdbool.h>

struct Paddle
{
    double x,y;
    double Colx1,Coly1,Colx2,Coly2;
    int lives;
    BITMAP *paddle;
};

struct Bufor
{
    BITMAP *bufor;
};

extern bool start_game(void);
extern void load_files(void);

extern void start_position_of_paddle(struct Paddle *);
extern void start_position_of_collider(struct Paddle *p);
extern void move_paddle(struct Paddle *);

#endif
