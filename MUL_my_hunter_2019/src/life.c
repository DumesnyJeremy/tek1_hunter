/*
** EPITECH PROJECT, 2019
** csflm
** File description:
** oui
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_hunter.h"

sprite_t *pos_sprite_life(sprite_t *test)
{
    test->pos_life.x = 1750;
    test->pos_life.y = 0;
    test->rect_life.top = 0;
    test->rect_life.left = 0;
    test->rect_life.width = 160;
    test->rect_life.height = 46;
    return (test);
}

void move_rect_life(sprite_t *test, int offset, int max_value)
{
    test->rect_life.top += offset;
    if (test->rect_life.top > max_value)
        test->game = -1000;
}

sprite_t *create_life_sprite(sprite_t *test)
{
    test->texture_life = sfTexture_createFromFile("other/life.png", NULL);
    if (!test->texture_life)
        return NULL;
    test->sprite_life = sfSprite_create();
    sfSprite_setTexture(test->sprite_life, test->texture_life, sfTrue);
    sfSprite_setTextureRect(test->sprite_life, test->rect_life);
    sfSprite_setPosition(test->sprite_life, test->pos_life);
}

void in_game(sfRenderWindow *w, sprite_t *test)
{
    test->cur_pos.x = sfMouse_getPosition((const sfWindow *)w).x;
    test->cur_pos.y = sfMouse_getPosition((const sfWindow *)w).y;
    sfSprite_setPosition(test->sprite_crossH, test->cur_pos);
    draw(w, test);
}
