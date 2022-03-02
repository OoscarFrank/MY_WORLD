/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** cond_button.c
*/

#include "../includes/map.h"

int quit_button(window *wndw, options *opt, cursor *c, maps *m)
{
    sfRenderWindow_close(wndw->window);
    return 0;
}

int continue_button(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->begin = 0;
    return 0;
}

int open_menu(window *wndw, options *opt, cursor *c, maps *m)
{
    sfEvent event;
    opt->begin = 3;
    return 0;
}

int resume_game(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->begin = 0;
    return 0;
}

int go_home(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->begin = 1;
    return 0;
}
