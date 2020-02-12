/*
** EPITECH PROJECT, 2019
** csflm
** File description:
** oui
*/

#include "../include/my_hunter.h"

void loop(sfRenderWindow *w, sprite_t *test)
{
    while (sfRenderWindow_isOpen(w)) {
        if (test->game == 0)
            sfRenderWindow_drawSprite(w, test->sprite_play, NULL);
        if (test->game > 0)
            in_game(w, test);
        if (test->game < 0) {
            dead_game(w, test);
            die_event(w, test);
        }
        manage_event(w, test);
        sfRenderWindow_display(w);
    }
}

int score(sprite_t *test)
{
    char *sc = NULL;
    my_put_nbr(test->nb, &sc);
    printf("%s\n", sc);
    test->font = sfFont_createFromFile("other/04b_25.ttf");
    if (!test->font)
        return 84;
    test->score = sfText_create();
    sfText_setString(test->score, sc);
    sfText_setFont(test->score, test->font);
    sfText_setPosition(test->score, (sfVector2f){340, 0});
    sfText_setCharacterSize(test->score, 50);
    return 0;
}

int main(int ac, char **av)
{
    const char *desc = "\n The game you will see is an epitech project, named "
    "My Hunter that I decided to do on the theme of Flappy Bird, this is why "
    "his name is Shooty Bird with custom sprites.\n Click to kill the bird and"
    "move with the pad\n Usage : ./my_hunter\n";
    if (ac == 2 && (av[1][0] == 'h' || av[1][1] == 'h')) {
        my_put_str(desc);
        return (0);
    }
    sfVideoMode m = {1920, 1080, 32};
    sprite_t *test = malloc(sizeof(sprite_t));
    sfRenderWindow *w = sfRenderWindow_create(m, "Shooty Bird", 2 | 4, NULL);
    if (!w)
        return 0;
    init_all(test, w);
    loop(w, test);
    destroy(w, test);
    free(test);
}

void init_all(sprite_t *test, sfRenderWindow *w)
{
    sfRenderWindow_setFramerateLimit(w, 60);
    test = init_struct(w, test);
    test->game = 0;
    score(test);
}

void dead_game(sfRenderWindow *window, sprite_t *test)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, test->sprite_bround, NULL);
    sfRenderWindow_drawSprite(window, test->sprite_die, NULL);
    sfRenderWindow_drawText(window, test->text, NULL);
    sfRenderWindow_drawText(window, test->score, NULL);
}