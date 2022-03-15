/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** cond_f_button.c
*/

#include "../includes/map.h"

int close_params(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->ar_btn[CLOSE_PARAMS].params = 0;
    opt->ar_btn[SAVE_FILE].params = 0;
    opt->ar_btn[OPEN_CHG_VIEW].params = 0;
    opt->ar_btn[OPEN_TURN].params = 0;
    opt->ar_btn[LOG_OUT].params = 0;
    opt->ar_btn[OPEN_ZOOM].params = 0;
    opt->ar_btn[RESET_MAP].params = 0;
    opt->ar_btn[SHORTCUTS].params = 0;
    opt->ar_btn[OPEN_PARAMS].params = 1;
    opt->ar_btn[LOAD_MAP].params = 0;
    opt->mv = -1;
    return 0;
}

int open_view(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->ar_btn[FLECHE_BAS].params = 1;
    opt->ar_btn[FLECHE_HAUT].params = 1;
    opt->ar_btn[FLECHE_DROITE].params = 1;
    opt->ar_btn[FLECHE_GAUCHE].params = 1;
    opt->ar_btn[CLOSE_VIEW].params = 1;
    opt->params = 6;
    return 0;
}

int close_view(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->ar_btn[FLECHE_BAS].params = 0;
    opt->ar_btn[FLECHE_HAUT].params = 0;
    opt->ar_btn[FLECHE_DROITE].params = 0;
    opt->ar_btn[FLECHE_GAUCHE].params = 0;
    opt->ar_btn[CLOSE_VIEW].params = 0;
    opt->params = 1;
    return 0;
}

int open_turn(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->ar_btn[TURN_MAP_L].params = 1;
    opt->ar_btn[TURN_MAP_R].params = 1;
    opt->ar_btn[TURN_MAP_H].params = 1;
    opt->ar_btn[TURN_MAP_B].params = 1;
    opt->ar_btn[CLOSE_TURN].params = 1;
    opt->params = 4;
    return 0;
}

int close_turn(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->ar_btn[TURN_MAP_L].params = 0;
    opt->ar_btn[TURN_MAP_R].params = 0;
    opt->ar_btn[TURN_MAP_H].params = 0;
    opt->ar_btn[TURN_MAP_B].params = 0;
    opt->ar_btn[CLOSE_TURN].params = 0;
    opt->params = 1;
    return 0;
}
