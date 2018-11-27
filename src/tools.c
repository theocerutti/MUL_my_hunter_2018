/*
** EPITECH PROJECT, 2018
** all functions tools / events
** File description:
** all functions tools / events
*/

#include "../include/my_hunter.h"

void move_cursor(sfVector2f *pos_cursor, sfRenderWindow *window)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);

    pos_cursor->x = pos_mouse.x - 51.2 / 2;
    pos_cursor->y = pos_mouse.y - 51.2 / 2;
}

void look_print_loose(life_st *life, txt_st *txt_loose)
{
    if (life->index == 3) {
        life->index = 3;
        sfText_setString(txt_loose[0].txt, "GAME OVER");
        sfText_setString(txt_loose[1].txt, "Press space to restart");
    }
}

void check_loose_restart(data_st *data, sfRenderWindow *window, sfEvent event)
{
    char str[50] = "Highest Score: ";

    if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace) {
        put_highest_score("score.txt", data->txt_score.score);
        sfText_setString(data->txt_high_score.txt, my_strcat(str,
        my_itoa(get_highest_score("score.txt"))));
        data->life.index = 0;
        data->lf = destroy_list(data->lf);
        sfSprite_setTexture(data->life.s, data->life.tab_life[0], sfTrue);
        sfText_setString(data->txt_score.txt, "0");
        data->txt_score.score = 0;
        sfText_setString(data->txt_loose[0].txt, NULL);
        sfText_setString(data->txt_loose[1].txt, NULL);
    }
}

void manage_mouse_click(data_st *data, sfRenderWindow *window, sfEvent event)
{
    sfVector2i pos_mouse;

    if (event.type == sfEvtMouseButtonPressed) {
        sfSound_play(data->sound_hit);
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        if (data->life.index != 3)
            look_if_kill(&data->lf, &pos_mouse, &data->txt_score);
    }
}

void analyse_events(data_st *data, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        manage_mouse_click(data, window, event);
        check_loose_restart(data, window, event);
    }
}