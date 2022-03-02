/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** cond_d_button.c
*/

#include "../includes/map.h"

int go_up(window *wndw, options *opt, cursor *c, maps *m)
{
    m->decal_y -= 50;
    return 0;
}

int turn_left(window *wndw, options *opt, cursor *c, maps *m)
{
    key_q(m);
    return 0;
}

int turn_right(window *wndw, options *opt, cursor *c, maps *m)
{
    key_d(m);
    return 0;
}

int turn_high(window *wndw, options *opt, cursor *c, maps *m)
{
    ++m->be;
    return 0;
}

int turn_low(window *wndw, options *opt, cursor *c, maps *m)
{
    --m->be;
    return 0;
}
