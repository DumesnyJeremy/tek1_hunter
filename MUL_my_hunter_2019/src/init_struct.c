/*
** EPITECH PROJECT, 2019
** csflm
** File description:
** oui
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_hunter.h"

sprite_t *create_clock(sprite_t *test)
{
    test->clock1 = sfClock_create();
    test->clock2 = sfClock_create();
    test->clock3 = sfClock_create();
    test->clock4 = sfClock_create();
    return test;
}

sprite_t *init_struct(sfRenderWindow *window, sprite_t *test)
{
    test->nb = 0;
    create_play_sprite(test);
    pos_sprite_duck(test);
    pos_sprite_dog(test);
    pos_sprite_life(test);
    createtext(test);
    create_background_sprite(test);
    create_duck_sprite(test);
    create_duck_sprite(test);
    create_cross_sprite(window, test);
    create_dog_sprite(test);
    create_life_sprite(test);
    create_die_sprite(test);
    sound(test);
    create_clock(test);
    return (test);
}