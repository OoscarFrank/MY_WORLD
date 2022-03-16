/*
** EPITECH PROJECT, 2022
** world
** File description:
** buttons plus
*/

#include "../includes/map.h"

int buttons_minus_x(window *wndw, options *opt, cursor *c, maps *m)
{
    --m->map_x;
    return 0;
}

int load_button(window *wndw, options *opt, cursor *c, maps *m)
{
    start_load(m);
    return 0;
}

int save_button(window *wndw, options *opt, cursor *c, maps *m)
{
    start_save(m);
    return 0;
}
