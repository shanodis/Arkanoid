#include "Arkanoid.h"
#include <allegro.h>

void initialise_alleg(void)
{
    if(allegro_init())
    {
        allegro_message("Blad inicjalizacji biblioteki Allegro!");
        exit(1);
    }
    if(install_keyboard())
    {
        allegro_message("Blad inicjalizacji klawiatury!");
        exit(1);
    }
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0))
    {
        allegro_message("Blad inicjalizacji grafiki!");
        exit(1);
    }
}
