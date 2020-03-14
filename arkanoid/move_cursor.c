#include "Arkanoid.h"

int go_down(int count,int *c1,int *c2,int *c3)
{
    if(count==1)
    {
        *c1=WHITE;
        *c2=PINK;
        return count=2;
    }
    else if(count==2)
    {
        *c2=WHITE;
        *c3=PINK;
        return count=3;
    }
}

int go_up(int count,int *c1,int *c2,int *c3)
{
    if(count==2)
    {
        *c1=PINK;
        *c2=WHITE;
        return count=1;
    }
    else if(count==3)
    {
        *c2=PINK;
        *c3=WHITE;
        return count=2;
    }
}
