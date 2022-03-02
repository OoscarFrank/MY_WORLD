/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** cond_t_button.c
*/

#include "../includes/map.h"

int zoom_out(window *wndw, options *opt, cursor *c, maps *m)
{
    --m->zoom;
    return 0;
}

int reset_button(window *wndw, options *opt, cursor *c, maps *m)
{
    reset_map(m);
    return 0;
}

int go_left(window *wndw, options *opt, cursor *c, maps *m)
{
    m->decal_x += 50;
    return 0;
}

int go_right(window *wndw, options *opt, cursor *c, maps *m)
{
    m->decal_x -= 50;
    return 0;
}

int go_down(window *wndw, options *opt, cursor *c, maps *m)
{
    m->decal_y += 50;
    return 0;
}
