/*
** EPITECH PROJECT, 2018
** Handle sprite
** File description:
** Handle sprite
*/

#include "../include/my_hunter.h"

void init_sprite(sprite *f, char *path)
{
    f->t = sfTexture_createFromFile(path, NULL);
    f->s = sfSprite_create();
    f->rect.top = 0;
    f->rect.left = 0;
    f->rect.width = f->offset[1];
    f->rect.height = f->height;
    sfSprite_setPosition(f->s, f->pos);
    sfSprite_setScale(f->s, f->scale_size);
    sfSprite_setTexture(f->s, f->t, sfTrue);
    sfSprite_setTextureRect(f->s, f->rect);
}

void anim_sprite(sfSprite **sprite, sfIntRect *rect, int *off, int max_value)
{
    rect->left += off[0];
    if (rect->left > max_value - off[1])
        rect->left = 0;
    sfSprite_setTextureRect(*sprite, *rect);
}

void anim_sprite_list(l_list list)
{
    node *temp = list;

    while (list != NULL) {
        anim_sprite(&list->f.s, &list->f.rect, list->f.offset, list->f.width);
        list = list->next;
    }
}

void draw_sprite(sfRenderWindow *window, l_list list)
{
    node *temp = list;

    while (list != NULL) {
        sfRenderWindow_drawSprite(window, list->f.s, NULL);
        list = list->next;
    }
}

void destroy_sprite(sfRenderWindow *window, l_list list)
{
    node *temp = list;

    while (list != NULL) {
        sfTexture_destroy(list->f.t);
        sfSprite_destroy(list->f.s);
        list = list->next;
    }
}