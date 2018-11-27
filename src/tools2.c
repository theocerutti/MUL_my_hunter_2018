/*
** EPITECH PROJECT, 2018
** all functions tools / events
** File description:
** all functions tools / events
*/

#include "../include/my_hunter.h"

void init_list_fish_data(data_st *data) {
    sprite gf = {91, 14, {31, 31}, {1, 1}, {1600, 100}, {3, 3}, 0, 0, 0};
    sprite bgf = {99, 17, {33, 33}, {1, 1}, {1600, 200}, {3, 3}, 0, 0, 0};
    sprite sgf = {63, 10, {21, 21}, {1, 1}, {1600, 300}, {3, 3}, 0, 0, 0};
    sprite yf = {96, 11, {32, 32}, {1, 1}, {1600, 400}, {3, 3}, 0, 0, 0};
    sprite tab_fish[4] = {gf, bgf, sgf, yf};
    l_list list_fish = NULL;

    data->lf = list_fish;
    for (int i = 0; i != 4; i++)
        data->tab_f[i] = tab_fish[i];
}

void init_clock(clock_st *clock)
{
    clock->clock = sfClock_create();
    clock->time = sfClock_getElapsedTime(clock->clock);
}

void init_txt(txt_st *t, char *path, char *str)
{
    t->txt = sfText_create();
    t->txt = sfText_create();
    t->font = sfFont_createFromFile(path);
    sfText_setString(t->txt, str);
    sfText_setFont(t->txt, t->font);
    sfText_setCharacterSize(t->txt, t->size);
    sfText_setPosition(t->txt, t->pos);
    sfText_setColor(t->txt, t->color);
}