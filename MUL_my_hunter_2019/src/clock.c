/*
** EPITECH PROJECT, 2019
** My_hunter
** File description:
** clock
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my_hunter.h"

void anim_duck(sfClock *clock1, sfIntRect *rect_duck, sfSprite *sprite1)
{
    sfTime time1;
    float seconds;
    time1 = sfClock_getElapsedTime(clock1);
    seconds = time1.microseconds / 1000000.0;

    if (seconds > 0.2)
    {
        move_rect_duck(rect_duck, 130, 520);
        sfSprite_setTextureRect(sprite1, *rect_duck);
        sfClock_restart(clock1);
    }
}

void posi_duck(sfClock *cl2, sfSprite *s2, float *x_duck, sprite_t *test)
{
    sfTime time2;
    float seconds;
    time2 = sfClock_getElapsedTime(cl2);
    seconds = time2.microseconds / 1000000.0;

    if (seconds > 0.004) {
        move_duck(x_duck, test);
        sfSprite_setPosition(s2, test->pos_duck);
        sfClock_restart(cl2);
    }
}

void posi_dog(sfClock *cl4, sfVector2f *pos_dog, sfSprite *s4, float *x_dog)
{
    sfTime time2;
    float seconds;
    time2 = sfClock_getElapsedTime(cl4);
    seconds = time2.microseconds / 1000000.0;

    if (seconds > 0.01) {
        move_dog(pos_dog, x_dog);
        sfSprite_setPosition(s4, *pos_dog);
        sfClock_restart(cl4);
    }
}