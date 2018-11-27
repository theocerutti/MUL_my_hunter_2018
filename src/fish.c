/*
** EPITECH PROJECT, 2018
** Handle fish
** File description:
** Handle fish
*/

#include "../include/my_hunter.h"

void look_if_kill(l_list *list_fish, sfVector2i *pos_mouse, txt_st *txt)
{
    node *t = *list_fish;

    for (int index = 0; t != NULL; index++) {
        if (t->f.pos.x < pos_mouse->x
            && pos_mouse->x < t->f.pos.x + t->f.offset[1] * t->f.scale_size.x
            && t->f.pos.y < pos_mouse->y
            && pos_mouse->y < t->f.pos.y + t->f.height * t->f.scale_size.y) {
            *list_fish = pop_index(*list_fish, index);
            add_score_fish(txt);
            return;
        }
        t = t->next;
    }
}

void add_score_fish(txt_st *txt)
{
    char *str = malloc(sizeof(char) * 100);

    txt->score += 1;
    str = my_itoa(txt->score);
    sfText_setString(txt->txt, str);
}

void move_fish(l_list list_fish)
{
    while (list_fish != NULL) {
        list_fish->f.pos.x -= list_fish->f.v.x;
        sfSprite_setPosition(list_fish->f.s, list_fish->f.pos);
        list_fish = list_fish->next;
    }
}

void destroy_fish_lim(l_list *list_fish, life_st *life)
{
    node *temp = *list_fish;

    for (int index = 0; temp != NULL; index++) {
        if (temp->f.pos.x < 0) {
            *list_fish = pop_index(*list_fish, index);
            life->index += 1;
            if (life->index >= 3)
                life->index = 3;
            sfSprite_setTexture(life->s, life->tab_life[life->index], sfTrue);
        }
        temp = temp->next;
    }
}

void create_random_fish(sprite *fish_tab, l_list *list_fish, life_st *life)
{
    int index_rd = rand() % -4;
    sfVector2f speed_rd = {(rand() % (10 - 5 + 1)) + 5, 0};
    sfVector2f pos_rd = {(rand() % (1700 - 1600 + 1)) + 1600, rand() % -580};
    sprite new_fish = fish_tab[index_rd];

    if (index_rd == 0)
        init_sprite(&new_fish, "lib/images/fish/fish_gray.png");
    else if (index_rd == 1)
        init_sprite(&new_fish, "lib/images/fish/fish_big_green.png");
    if (index_rd == 2)
        init_sprite(&new_fish, "lib/images/fish/fish_small_green.png");
    else if (index_rd == 3)
        init_sprite(&new_fish, "lib/images/fish/fish_yellow.png");
    new_fish.pos = pos_rd;
    new_fish.v = speed_rd;
    *list_fish = push(*list_fish, new_fish);
    destroy_fish_lim(list_fish, life);
}