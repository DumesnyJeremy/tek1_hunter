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

sprite_t *destroy(sfRenderWindow *window, sprite_t *test)
{
    sfRenderWindow_destroy(window);
    sfSprite_destroy(test->sprite_bround);
    sfTexture_destroy(test->texture_bround);
    sfSprite_destroy(test->sprite_duck);
    sfTexture_destroy(test->texture_duck);
    sfSprite_destroy(test->sprite_crossH);
    sfTexture_destroy(test->texture_crossH);
    sfSprite_destroy(test->sprite_dog);
    sfTexture_destroy(test->texture_dog);
    sfSprite_destroy(test->sprite_life);
    sfTexture_destroy(test->texture_life);
    sfTexture_destroy(test->texture_play);
    sfMusic_destroy(test->music_shoot);
}

int createtext(sprite_t *test)
{
    test->font = sfFont_createFromFile("other/04b_25.ttf");
    if (!test->font)
        return 84;
    test->text = sfText_create();
    sfText_setString(test->text, "Your score is :");
    sfText_setFont(test->text, test->font);
    sfText_setCharacterSize(test->text, 50);
    return 0;
}

sprite_t *pos_sprite_duck(sprite_t *test)
{
    srand(time(NULL));
    int y = rand() % 800;

    test->x_duck = -130;
    test->cur_pos;
    test->pos_duck.x = test->x_duck;
    test->pos_duck.y = y;
    test->rect_duck.top = 0;
    test->rect_duck.left = 0;
    test->rect_duck.width = 130;
    test->rect_duck.height = 130;
    return (test);
}

sprite_t *pos_sprite_dog(sprite_t *test)
{
    test->x_dog = -110;
    test->pos_dog.x = test->x_dog;
    test->pos_dog.y = 900;
    test->rect_dog.top = 0;
    test->rect_dog.left = 0;
    test->rect_dog.width = 100;
    test->rect_dog.height = 500;
    return (test);
}

int hitbox(sprite_t *test, int width_duck, int duck_height)
{
    if ((test->cur_pos.x >= test->pos_duck.x
    && test->cur_pos.x <= test->pos_duck.x + width_duck)
    && (test->cur_pos.y >= test->pos_duck.y
    && test->cur_pos.y <= test->pos_duck.y + duck_height)) {
        return (1);
    }
    else
        return (0);
}