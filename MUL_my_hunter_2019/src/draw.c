/*
** EPITECH PROJECT, 2019
** oui
** File description:
** move pixel
*/

#include "../include/my_hunter.h"

void draw(sfRenderWindow *window, sprite_t *test)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, test->sprite_bround, NULL);
    sfRenderWindow_drawSprite(window, test->sprite_duck, NULL);
    sfRenderWindow_drawSprite(window, test->sprite_dog, NULL);
    sfRenderWindow_drawSprite(window, test->sprite_life, NULL);
    anim_duck(test->clock1, &test->rect_duck, test->sprite_duck);
    posi_duck(test->clock2, test->sprite_duck, &test->x_duck, test);
    posi_dog(test->clock4, &test->pos_dog, test->sprite_dog, &test->x_dog);
    sfRenderWindow_drawSprite(window, test->sprite_crossH, NULL);
    sfRenderWindow_drawText(window, test->text, NULL);
    sfRenderWindow_drawText(window, test->score, NULL);
}

void my_put_str(const char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++)
        my_put_char(str[i]);
}

void my_put_char(char c)
{
    write(1, &c, 1);
}