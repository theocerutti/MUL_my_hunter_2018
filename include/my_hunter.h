/*
** EPITECH PROJECT, 2018
** Header of my_hunter.h
** File description:
** Header of my_hunter.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

void move_ship(sprite *ship, int offsetx, int offsety);
void manage_move_ship(sprite *ship);
l_list destroy_list(l_list list);
l_list push(l_list list, sprite new_f);
l_list pop(l_list list);
l_list pop_deb(l_list list);
l_list pop_index(l_list list, int index);
void print_list(l_list list);
int is_empty(l_list list);
void init_sprite(sprite *f, char *path);
void init_txt(txt_st *t, char *path, char *str);
void anim_sprite_list(l_list list_fish);
void draw_sprite(sfRenderWindow *window, l_list list);
void destroy_sprite(sfRenderWindow *window, l_list list);
void move_fish(l_list list_fish);
void destroy_fish_lim(l_list *list_fish, life_st *life);
void anim_sprite(sfSprite **sprite, sfIntRect *rect, int *off, int max_value);
char *my_itoa(int nb);
void check_loose_restart(data_st *data, sfRenderWindow *window, sfEvent event);
void look_print_loose(life_st *life, txt_st *txt_loose);
void manage_mouse_click(data_st *data, sfRenderWindow *window, sfEvent event);
void analyse_events(data_st *data, sfRenderWindow *window);
void move_cursor(sfVector2f *pos_cursor, sfRenderWindow *window);
void look_if_kill(l_list *list_fish, sfVector2i *pos_mouse, txt_st *txt);
void create_random_fish(sprite *fish_tab, l_list *list_fish, life_st *life);
void add_score_fish(txt_st *txt);
int my_atoi(char *str);
int get_highest_score(char *path_file);
void put_highest_score(char *path_file, int score);
char *my_strcat(char *dest, char const *src);
void init_list_background_data(data_st *data);
void init_list_fish_data(data_st *data);
void init_txt_data(data_st *data);
void init_music_data(data_st *data);
void init_heart_cursor_data(data_st *data);
void init_clock_data(data_st *data);
void draw_all(data_st *data, sfRenderWindow *window);
void destroy_all(data_st *data, sfRenderWindow *window);
void move_all(data_st *data, sfRenderWindow *window);
void init_clock(clock_st *clock);
void do_anim_create(data_st *d);
void launch_hunter(data_st *data, sfRenderWindow *window);