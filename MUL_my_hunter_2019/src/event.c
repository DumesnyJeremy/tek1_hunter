/*
** EPITECH PROJECT, 2019
** oui
** File description:
** move pixel
*/

#include "../include/my_hunter.h"

int manage_event(sfRenderWindow *window, sprite_t *test)
{
    while (sfRenderWindow_pollEvent(window, &test->event))
    {
        if (test->event.type == sfEvtMouseButtonPressed)
            test->game++;
        if (test->event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(test->music_shoot);
        }
        if (test->event.type == sfEvtMouseButtonPressed
        && hitbox(test, 150, 150)) {
            kill_duck(window, test);
        }
        else if (test->event.type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
    }
}

void kill_duck(sfRenderWindow *window, sprite_t *test)
{
    srand(time(NULL));
    int y = rand() % 800;
    test->x_duck = -210;
    test->pos_duck.y = y;
    test->nb++;
    score(test);
}

int die_event(sfRenderWindow *window, sprite_t *test)
{
    while (sfRenderWindow_pollEvent(window, &test->event))
    {
        if (test->event.type == sfEvtMouseButtonPressed
        && test->game < 0) {
            test->game = 1;
            test->nb = 0;
            score(test);
            test->speed = 1;
            test->rect_life.top = 0;
            pos_sprite_life(test);
            sfRenderWindow_drawSprite(window, test->sprite_life, NULL);
            create_life_sprite(test);
        }
        else if (test->event.type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(window);
    }
}