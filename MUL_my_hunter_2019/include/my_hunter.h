/*
** EPITECH PROJECT, 2019
** lib.h
** File description:
** My hunter
*/

#ifndef MY_H
#define MY_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/System.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

typedef struct sprite_s
{
    sfRenderWindow *window;
    sfMusic* music_shoot;

    sfEvent event;
    sfMouseButtonEvent mouse;

    sfText* text, *score, *life;
    sfFont* font;
    char *sc;
    int nb;

    sfSprite* sprite_bround;
    sfTexture* texture_bround;
    int game;

    sfSprite* sprite_play;
    sfTexture* texture_play;

    sfSprite* sprite_die;
    sfTexture* texture_die;

    sfSprite* sprite_crossH;
    sfTexture* texture_crossH;

    sfSprite* sprite_dog;
    sfTexture* texture_dog;
    sfIntRect rect_dog;
    sfVector2f pos_dog;
    float x_dog;

    sfSprite* sprite_duck;
    sfTexture* texture_duck;
    sfIntRect rect_duck;
    sfVector2f pos_duck;
    float x_duck;
    int speed;

    sfSprite* sprite_life;
    sfTexture* texture_life;
    sfIntRect rect_life;
    sfVector2f pos_life;

    sfVector2f cur_pos;
    sfVector2f pos_shoot;

    sfClock *clock1;
    sfClock *clock2;
    sfClock *clock3;
    sfClock *clock4;
} sprite_t;

void anim_duck(sfClock *clock1, sfIntRect *rect_duck, sfSprite *sprite1);
void posi_duck(sfClock *cl2, sfSprite *s2, float *x_duck, sprite_t *test);
void anim_dog(sfClock *clock3, sfIntRect *rect_dog, sfSprite *sprite3);
void posi_dog(sfClock *, sfVector2f *, sfSprite *, float *x_dog);

void move_rect_duck(sfIntRect *rect_duck, int offset, int max_value);
void move_duck(float *x_duck, sprite_t *test);
void move_rect_dog(sfIntRect *rect_dog, int offset, int max_value);
void move_dog(sfVector2f *pos_dog, float *x_dog);

void move_rect_life(sprite_t *test, int offset, int max_value);
int hitbox(sprite_t *param_spr, int width_duck, int duck_height);

void loop(sfRenderWindow *w, sprite_t *test);
int main(int ac, char **as);
void in_game(sfRenderWindow *w, sprite_t *test);
void dead_game(sfRenderWindow *window, sprite_t *test);
void init_all(sprite_t *test, sfRenderWindow *window);
sprite_t *create_background_sprite(sprite_t *);
sprite_t *create_duck_sprite(sprite_t *);
sprite_t *create_cross_sprite(sfRenderWindow *, sprite_t *);
sprite_t *create_dog_sprite(sprite_t *);
sprite_t *create_play_sprite(sprite_t *test);
sprite_t *create_die_sprite(sprite_t *test);

sprite_t *create_life_sprite(sprite_t *test);
sprite_t *pos_sprite_life(sprite_t *test);

sprite_t *Pos_sprite(sprite_t *);
sprite_t *Pos_click(sprite_t *);
sprite_t *pos_sprite_duck(sprite_t *);
sprite_t *pos_sprite_dog(sprite_t *);

sprite_t *destroy(sfRenderWindow *window, sprite_t *);
int createtext(sprite_t *);
int create_life(sprite_t *);
int score(sprite_t *);
int sound(sprite_t *);
sprite_t *init_struct(sfRenderWindow *, sprite_t *);

void my_put_char(char c);
void my_put_str(const char *str);
void my_put_nbr(int nb, char **stock);
char *my_strcat(char *dest, char const *src, int n);
int my_strlen(char const *str);

void draw(sfRenderWindow *, sprite_t *);
int manage_event(sfRenderWindow *, sprite_t *);
void kill_duck(sfRenderWindow *window, sprite_t *test);
int die_event(sfRenderWindow *window, sprite_t *test);

#endif