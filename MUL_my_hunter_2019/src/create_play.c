/*
** EPITECH PROJECT, 2019
** Texture all Srpite
** File description:
** Texture 1/2/3
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_hunter.h"

sprite_t *create_play_sprite(sprite_t *test)
{
    test->texture_play = sfTexture_createFromFile("other/menu.jpg", NULL);
    if (!test->texture_play)
        return NULL;
    test->sprite_play = sfSprite_create();
    sfSprite_setTexture(test->sprite_play, test->texture_play, sfTrue);
}

sprite_t *create_die_sprite(sprite_t *test)
{
    test->texture_die = sfTexture_createFromFile("other/game_over.png", NULL);
    if (!test->texture_die)
        return NULL;
    test->sprite_die = sfSprite_create();
    sfSprite_setTexture(test->sprite_die, test->texture_die, sfTrue);
}

int sound(sprite_t *test)
{
    test->music_shoot = sfMusic_createFromFile("other/offf.ogg");
    if (!test->music_shoot)
        return 84;
    return (0);
}