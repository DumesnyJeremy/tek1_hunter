/*
** EPITECH PROJECT, 2019
** Texture all Srpite
** File description:
** Texture 1/2/3
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my_hunter.h"

sprite_t *create_background_sprite(sprite_t *test)
{
    test->texture_bround = sfTexture_createFromFile("other/bg.jpg", NULL);
    if (!test->texture_bround)
        return NULL;
    test->sprite_bround = sfSprite_create();
    sfSprite_setTexture(test->sprite_bround, test->texture_bround, sfTrue);
}

sprite_t *create_duck_sprite(sprite_t *test)
{
    test->texture_duck = sfTexture_createFromFile("other/bird.png", NULL);
    if (!test->texture_duck)
        return NULL;
    test->sprite_duck = sfSprite_create();
    sfSprite_setTexture(test->sprite_duck, test->texture_duck, sfTrue);
    sfSprite_setTextureRect(test->sprite_duck, test->rect_duck);
    sfSprite_setPosition(test->sprite_duck, test->pos_duck);
}

sprite_t *create_cross_sprite(sfRenderWindow *window, sprite_t *test)
{
    test->texture_crossH = sfTexture_createFromFile("other/pipe.png", NULL);
    if (!test->texture_crossH)
        return NULL;
    test->sprite_crossH = sfSprite_create();
    sfSprite_setTexture(test->sprite_crossH, test->texture_crossH, sfTrue);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
}

sprite_t *create_dog_sprite(sprite_t *test)
{
    test->texture_dog = sfTexture_createFromFile("other/dog.png", NULL);
    if (!test->texture_dog)
        return NULL;
    test->sprite_dog = sfSprite_create();
    sfSprite_setTexture(test->sprite_dog, test->texture_dog, sfTrue);
    sfSprite_setPosition(test->sprite_dog, test->pos_dog);
    sfSprite_setTextureRect(test->sprite_dog, test->rect_dog);
}