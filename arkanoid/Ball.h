#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <allegro.h>

struct Ball
{
    double x,y;
    double dx,dy;
    double speed;
    BITMAP *ball;

}b;

extern void start_position_of_ball(struct Ball *);
extern void ball_movement(struct Ball *);
extern int collision_with_paddle(struct Ball *b,struct Paddle *p);

#endif
