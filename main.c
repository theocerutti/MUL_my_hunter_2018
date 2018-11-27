/*
** EPITECH PROJECT, 2018
** My_Hunter
** File description:
** My_Hunter
*/

#include "include/my_hunter.h"

int check_error(int ac)
{
    if (ac != 1) {
        my_putstr("HELP\n\nThe goal of this game is to have the best score.");
        my_putstr("\nTo increase your score you must kill fishes by pressing");
        my_putstr(" the mouse button left.\n/!\\ Take care /!\\ If a ");
        my_putstr("fish leave the screen you loose a life.\nYou have 3 life.");
        my_putstr("\nIf you don't have life anymore it's a GAME OVER.\n");
        return (84);
    }
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    sfVideoMode v_mode = {1600, 600, 32};
    data_st data;

    if (check_error(ac) == 84)
        return (84);
    init_list_background_data(&data);
    init_list_fish_data(&data);
    init_txt_data(&data);
    init_music_data(&data);
    init_heart_cursor_data(&data);
    init_clock_data(&data);
    window = sfRenderWindow_create(v_mode, "My_Hunter", sfDefaultStyle, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    srand(time(NULL));
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window))
        launch_hunter(&data, window);
    destroy_all(&data, window);
    return (0);
}

