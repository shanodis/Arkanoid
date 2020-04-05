#include "Arkanoid.h"
#include "Game.h"

volatile int speed_counter=0;

void increment_speed_counter(void)
{
    speed_counter++;
}

int main(void)
{
    /*Inicjalizacja*/
    initialise_alleg();
    LOCK_VARIABLE(speed_counter);
    LOCK_FUNCTION(increment_speed_counter);
    install_int_ex(increment_speed_counter, BPS_TO_TIMER(60));

    /*Przebieg gry*/
    while (!key[KEY_ESC])
    {
        while (speed_counter > 0)
            speed_counter--;
        create_menu();
        load_files();
        while(start_game()!=false && !key[KEY_ESC]);
    }
    allegro_exit();

    return 0;
}
END_OF_MAIN();
