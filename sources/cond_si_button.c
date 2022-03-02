/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** cond_si_button.c
*/

#include "../includes/map.h"

int close_shortcuts(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->ar_btn[CLOSE_SHORTCUTS].params = 0;
    opt->params = 1;
    return 0;
}

int zoom_in(window *wndw, options *opt, cursor *c, maps *m)
{
    ++m->zoom;
    return 0;
}
