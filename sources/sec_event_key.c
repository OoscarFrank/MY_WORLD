/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** event key
*/

#include "../includes/map.h"

void key_q(maps *m)
{
    if (m->al >= 1)
        m->al -= 2;
}

void key_d(maps *m)
{
    if ((m->al < 145) && (m->al >= 0))
        m->al += 2;
}
