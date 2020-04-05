#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include <allegro.h>

struct Ball
{
    double x,y;/*dla obrazka*/
    double dx,dy;
    double x1,x2,y1,y2;/*dla kolidera*/
    int radius;

    double speed;
    BITMAP *ball;

};

extern void start_position_of_ball(struct Ball *);
extern void ball_movement(struct Ball *);
extern void set_new_direction(struct Ball *);

#endif
