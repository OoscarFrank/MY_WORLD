/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** cond_fi_button.c
*/

#include "../includes/map.h"

int open_p(window *wndw, options *opt)
{
    opt->ar_btn[CLOSE_PARAMS].params = 1;
    opt->ar_btn[SAVE_FILE].params = 1;
    opt->ar_btn[OPEN_CHG_VIEW].params = 1;
    opt->ar_btn[OPEN_TURN].params = 1;
    opt->ar_btn[LOG_OUT].params = 1;
    opt->ar_btn[OPEN_ZOOM].params = 1;
    opt->ar_btn[RESET_MAP].params = 1;
    opt->ar_btn[SHORTCUTS].params = 1;
    opt->ar_btn[OPEN_PARAMS].params = 0;
    opt->ar_btn[LOAD_MAP].params = 1;
    return 0;
}

int open_params(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->params = 1;
    opt->mv = 1;
    return 0;
}


int open_zoom(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->ar_btn[ZOOM].params = 1;
    opt->ar_btn[DZOOM].params = 1;
    opt->ar_btn[CLOSE_ZOOM].params = 1;
    opt->params = 4;
    return 0;
}

int close_zoom(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->ar_btn[ZOOM].params = 0;
    opt->ar_btn[DZOOM].params = 0;
    opt->ar_btn[CLOSE_ZOOM].params = 0;
    opt->params = 1;
    return 0;
}

int open_shortcuts(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->ar_btn[CLOSE_SHORTCUTS].params = 1;
    opt->params = 5;
    return 0;
}
