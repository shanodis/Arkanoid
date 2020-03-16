#include "Game.h"
#include "Ball.h"
#include "Arkanoid.h"

static void load_textures(struct Paddle *p,struct Ball *b,struct Bufor *buf)
{
    p->paddle=load_bitmap("data/paddle.bmp",NULL);
    b->ball=load_bitmap("data/ball.bmp",NULL);
    buf->bufor=create_bitmap(800,600);
}

static void draw_start(struct Paddle p,struct Ball b,struct Bufor buf,struct Myfont f)
{
    clear_to_color(buf.bufor,WHITE);
    textout_centre_ex(buf.bufor,f.myfont,"Press Space",SCREEN_W/2,SCREEN_H/2,BLACK,WHITE);
    draw_sprite(buf.bufor,p.paddle,p.x,p.y);
    draw_sprite(buf.bufor,b.ball,b.x,b.y);
    blit(buf.bufor,screen,0,0,0,0,800,600);
}

static void draw_game(struct Paddle p,struct Ball b,struct Bufor buf)
{
    clear_to_color(buf.bufor,WHITE);
    draw_sprite(buf.bufor,p.paddle,p.x,p.y);
    draw_sprite(buf.bufor,b.ball,b.x,b.y);
    rect(buf.bufor,p.Colx1,p.Coly1,p.Colx2,p.Coly2,BLACK);
    blit(buf.bufor,screen,0,0,0,0,800,600);
}

void load_files(void)
{
    load_textures(&p,&b,&buf);
    show_video_bitmap(buf.bufor);
}

void start_game(void)
{
    start_position_of_paddle(&p);
    start_position_of_collider(&p);

    start_position_of_ball(&b);

    while(!key[KEY_SPACE])
    {
        move_paddle(&p);
        /*Drawing*/
        draw_start(p,b,buf,f);
    }
}

void course_of_the_game(void)
{

    while(!key[KEY_ESC])
    {
        move_paddle(&p);
        collision_with_paddle(&b,&p);
        ball_movement(&b);
        draw_game(p,b,buf);
    }
}
