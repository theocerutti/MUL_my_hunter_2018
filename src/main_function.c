/*
** EPITECH PROJECT, 2018
** all main function
** File description:
** all main function
*/

#include "../include/my_hunter.h"

void draw_all(data_st *data, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfWhite);
    anim_sprite_list(data->l_bg);
    draw_sprite(window, data->l_bg);
    sfRenderWindow_drawSprite(window, data->ship.s, NULL);
    draw_sprite(window, data->lf);
    sfRenderWindow_drawSprite(window, data->heart_s, NULL);
    sfRenderWindow_drawText(window, data->txt_score.txt, NULL);
    sfRenderWindow_drawText(window, data->txt_high_score.txt, NULL);
    sfRenderWindow_drawText(window, data->txt_loose[0].txt, NULL);
    sfRenderWindow_drawText(window, data->txt_loose[1].txt, NULL);
    sfRenderWindow_drawSprite(window, data->cursor.s, NULL);
    sfRenderWindow_display(window);
}

void destroy_all(data_st *data, sfRenderWindow *window)
{
    destroy_sprite(window, data->lf);
    destroy_sprite(window, data->l_bg);
    sfSound_destroy(data->sound_hit);
    sfSoundBuffer_destroy(data->buffer_sound);
    sfMusic_destroy(data->music);
    sfRenderWindow_destroy(window);
    put_highest_score("score.txt", data->txt_score.score);
}

void move_all(data_st *data, sfRenderWindow *window)
{
    manage_move_ship(&data->ship);
    move_cursor(&data->cursor.pos, window);
    sfSprite_setPosition(data->cursor.s, data->cursor.pos);
    move_fish(data->lf);
}

void do_anim_create(data_st *d)
{
    d->tab_clock[0].time = sfClock_getElapsedTime(d->tab_clock[0].clock);
    d->tab_clock[1].time = sfClock_getElapsedTime(d->tab_clock[1].clock);
    d->tab_clock[2].time = sfClock_getElapsedTime(d->tab_clock[2].clock);
    d->tab_clock[0].s = d->tab_clock[0].time.microseconds / 1000000.0;
    d->tab_clock[1].s = d->tab_clock[1].time.microseconds / 1000000.0;
    d->tab_clock[2].s = d->tab_clock[2].time.microseconds / 1000000.0;
    if (d->tab_clock[0].s > 0.7) {
        create_random_fish(d->tab_f, &d->lf, &d->life);
        sfClock_restart(d->tab_clock[0].clock);
    }
    if (d->tab_clock[1].s > 0.25) {
        anim_sprite_list(d->lf);
        sfClock_restart(d->tab_clock[1].clock);
    }
    if (d->tab_clock[2].s > 0.1) {
        anim_sprite(&d->ship.s, &d->ship.rect, d->ship.offset, d->ship.width);
        sfClock_restart(d->tab_clock[2].clock);
    }
}

void launch_hunter(data_st *data, sfRenderWindow *window)
{
    analyse_events(data, window);
    do_anim_create(data);
    look_print_loose(&data->life, data->txt_loose);
    move_all(data, window);
    draw_all(data, window);
}