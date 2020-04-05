#include "Game.h"
#include "Ball.h"
#include "Arkanoid.h"
#include <stdbool.h>
#include <time.h>

void print_time(struct Bufor,int *,int *,int *,long long int *,long long int *);

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

static void draw_game(struct Paddle p,struct Ball b,struct Bufor buf,int *sec,int *d_sec,int *min,long long int *check,long long int *counter)
{
    clear_to_color(buf.bufor,WHITE);
    draw_sprite(buf.bufor,p.paddle,p.x,p.y);
    draw_sprite(buf.bufor,b.ball,b.x,b.y);
    print_time(buf,sec,d_sec,min,check,counter);
    blit(buf.bufor,screen,0,0,0,0,800,600);
}

static bool player_lives(struct Paddle *p)
{
    /*Tutaj bêdzie zaimplementowane ¿ycie gracza*/
    return false;
}


void print_time(struct Bufor buf,int *sec,int *d_sec,int *min,long long int *check,long long int *counter)
{
    textprintf_centre_ex(buf.bufor,f.myfont,SCREEN_W/2,SCREEN_H/2,BLACK,-1,"Time: %d:%d%d",*min,*d_sec,*sec);

    *counter+=1;
    if(*counter==*check)
    {
        *sec+=1;
        *check+=1000;

        if(*d_sec==5 && *sec==10)
        {
            *min+=1;
            *sec=0;
            *d_sec=0;
        }
        if(*sec==10)
        {
            *d_sec+=1;
            *sec=0;
        }
    }
}

void start_position_of_colliders(struct Ball *b,struct Paddle *p)
{
    p->Colx1=SCREEN_W/2-50;
    p->Coly1=SCREEN_H-40;

    p->Colx2=SCREEN_W/2+54;
    p->Coly2=SCREEN_H-40+24;

    b->x1=SCREEN_W/2-10;
    b->x2=SCREEN_W/2+10;
    b->y1=SCREEN_H-71;
    b->y2=SCREEN_H-51;
    b->radius=10;
}

bool collision_with_paddle(struct Ball *b,struct Paddle *p)
{
    if((b->x1+20) >= p->Colx1 && b->x1 <= p->Colx1+104 && b->y1+20 >= p->Coly1 && b->y1 <= p->Coly1+24)
    {
        b->dy*=-1;
        set_new_direction(b);
    }

    else if(b->y>=SCREEN_H-20)
        return false;
    return true;
}

void load_files(void)
{
    struct Bufor buf;
    struct Paddle p;
    struct Ball b;

    load_textures(&p,&b,&buf);
    show_video_bitmap(buf.bufor);
}

bool start_game(void)
{
    /*Start gry, pozycje startowe obiektów*/
    struct Bufor buf;
    struct Paddle p;
    struct Ball b;

    start_position_of_paddle(&p);
    start_position_of_colliders(&b,&p);

    start_position_of_ball(&b);

    while(!key[KEY_SPACE])
    {
        move_paddle(&p);
        draw_start(p,b,buf,f);
    }

    /*Przebieg gry*/
    int d_sec=0,sec=0,min=0;
    long long int check=1000,counter=0;

    while(!key[KEY_ESC])
    {
        if(collision_with_paddle(&b,&p)==false) break;
        /*{
            if(player_lives(&p)==false)
               return false;
        }*/
        /*wyzej fragment kodu do zycia gracza*/
        move_paddle(&p);
        ball_movement(&b);
        draw_game(p,b,buf,&sec,&d_sec,&min,&check,&counter);
    }
    return true;
}
