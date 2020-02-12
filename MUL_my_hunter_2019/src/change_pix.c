/*
** EPITECH PROJECT, 2019
** My_hunter
** File description:
** move pixel
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/my_hunter.h"

void move_rect_duck(sfIntRect *rect_duck, int offset, int max_value)
{
    rect_duck->left += offset;
    if (rect_duck->left >= max_value)
        rect_duck->left = 0;
}

void move_duck(float *x_duck, sprite_t *test)
{
    test->speed = test->nb + 1;
    if (*x_duck < 1920) {
        test->pos_duck = (sfVector2f){*x_duck, test->pos_duck.y};
        *x_duck += test->speed;
    }
    if (*x_duck >= 1920) {
        test->pos_duck = (sfVector2f){-130, test->pos_duck.y};
        *x_duck = -130;
        test->pos_duck.y = rand()%800;
        move_rect_life(test, 46, 156);
        sfSprite_setTextureRect(test->sprite_life, test->rect_life);
    }
}

void move_dog(sfVector2f *pos_dog, float *x_dog)
{
    if (*x_dog > -100) {
        *pos_dog = (sfVector2f){*x_dog, pos_dog->y};
        *x_dog -= 4.0;
        pos_dog->y = 0;
    }
    if (*x_dog <= -100) {
        *pos_dog = (sfVector2f){2000, pos_dog->y};
        *x_dog = 2000;
        pos_dog->y = 0;
    }
}