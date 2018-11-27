/*
** EPITECH PROJECT, 2018
** Handle fish
** File description:
** Handle fish
*/

#include "../include/my_hunter.h"

void move_ship(sprite *ship, int offsetx, int offsety)
{
    if (ship->pos.x + offsetx < 150 && ship->pos.x + offsetx > -30)
        ship->pos.x += offsetx;
    if (ship->pos.y + offsety < 600 - 100 && ship->pos.y + offsety > -30)
        ship->pos.y += offsety;
    sfSprite_setPosition(ship->s, ship->pos);
}

void manage_move_ship(sprite *ship)
{
    if ((sfKeyboard_isKeyPressed(sfKeyZ)))
        move_ship(ship, 0, -ship->v.y);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_ship(ship, 0, ship->v.y);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move_ship(ship, ship->v.x, 0);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_ship(ship, -ship->v.x, 0);
}