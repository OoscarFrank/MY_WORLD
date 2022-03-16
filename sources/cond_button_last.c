/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** cond_button_last.c
*/

#include "../includes/map.h"

int rzero(window *wndw, options *opt, cursor *c, maps *m)
{
    return 0;
}

int buttons_minus_y(window *wndw, options *opt, cursor *c, maps *m)
{
    --m->map_y;
    return 0;
}


int buttons_plus_x(window *wndw, options *opt, cursor *c, maps *m)
{
    ++m->map_x;
    return 0;
}

int buttons_plus_y(window *wndw, options *opt, cursor *c, maps *m)
{
    ++m->map_y;
    return 0;
}

void ten_part_button(window *wndw, options *opt, cursor *c, maps *m)
{
    factory_button(opt, &buttons_plus_y, (sfIntRect){3808, 0, 40, 40},
        (sfVector2f){210, 600});
    opt->ar_btn[PLUS_Y].params = 0;
    opt->ar_btn[PLUS_Y].screen = 0;
    factory_button(opt, &buttons_minus_y, (sfIntRect){3848, 0, 40, 40},
        (sfVector2f){270, 600});
    opt->ar_btn[MOINS_Y].params = 0;
    opt->ar_btn[MOINS_Y].screen = 0;
    factory_button(opt, &rzero, (sfIntRect){3888, 0, 40, 40},
        (sfVector2f){150, 550});
    opt->ar_btn[DEF_X].params = 0;
    opt->ar_btn[DEF_X].screen = 0;
    factory_button(opt, &rzero, (sfIntRect){3928, 0, 40, 40},
        (sfVector2f){150, 600});
    opt->ar_btn[DEF_Y].params = 0;
    opt->ar_btn[DEF_Y].screen = 0;
}