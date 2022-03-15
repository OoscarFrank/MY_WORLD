/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** part_func_button.c
*/

#include "../includes/map.h"

void nine_part_button(window *wndw, options *opt, cursor *c, maps *m)
{
    factory_button(opt, &start_load, (sfIntRect){3608, 0, 200, 40},
        (sfVector2f){140, 250});
    opt->ar_btn[LOAD_MAP].params = 0;
    opt->ar_btn[LOAD_MAP].screen = 0;
}

void eight_part_button(window *wndw, options *opt, cursor *c, maps *m)
{
    factory_button(opt, &reset_button, (sfIntRect){3178, 0, 200, 40},
        (sfVector2f){140, 490});
    opt->ar_btn[RESET_MAP].params = 0;
    opt->ar_btn[RESET_MAP].screen = 0;
    factory_button(opt, &open_shortcuts, (sfIntRect){3408, 0, 200, 40},
        (sfVector2f){140, 840});
    opt->ar_btn[SHORTCUTS].params = 0;
    opt->ar_btn[SHORTCUTS].screen = 0;
    factory_button(opt, &close_shortcuts, (sfIntRect){3378, 0, 30, 30},
        (sfVector2f){1300, 270});
    opt->ar_btn[CLOSE_SHORTCUTS].params = 0;
    opt->ar_btn[CLOSE_SHORTCUTS].screen = 0;
    nine_part_button(wndw, opt, c, m);
}

void seven_part_button(window *wndw, options *opt, cursor *c, maps *m)
{
    factory_button(opt, &open_zoom, (sfIntRect){2978, 0, 200, 40},
        (sfVector2f){140, 430});
    opt->ar_btn[OPEN_ZOOM].params = 0;
    opt->ar_btn[OPEN_ZOOM].screen = 0;
    factory_button(opt, &zoom_in, (sfIntRect){2141, 0, 60, 60},
        (sfVector2f){1850, 80});
    opt->ar_btn[ZOOM].params = 0;
    opt->ar_btn[ZOOM].screen = 0;
    factory_button(opt, &zoom_out, (sfIntRect){2201, 0, 60, 60},
        (sfVector2f){1850, 160});
    opt->ar_btn[DZOOM].params = 0;
    opt->ar_btn[DZOOM].screen = 0;
    factory_button(opt, &close_zoom, (sfIntRect){3378, 0, 30, 30},
        (sfVector2f){1800, 80});
    opt->ar_btn[CLOSE_ZOOM].params = 0;
    opt->ar_btn[CLOSE_ZOOM].screen = 0;
    eight_part_button(wndw, opt, c, m);
}

void sixth_part_button(window *wndw, options *opt, cursor *c, maps *m)
{
    factory_button(opt, &turn_low, (sfIntRect){2441, 0, 60, 60},
        (sfVector2f){1760, 800});
    opt->ar_btn[TURN_MAP_B].params = 0;
    opt->ar_btn[TURN_MAP_B].screen = 0;
    factory_button(opt, &turn_right, (sfIntRect){2321, 0, 60, 60},
        (sfVector2f){1840, 800});
    opt->ar_btn[TURN_MAP_R].params = 0;
    opt->ar_btn[TURN_MAP_R].screen = 0;
    factory_button(opt, &turn_high, (sfIntRect){2381, 0, 60, 60},
        (sfVector2f){1760, 720});
    opt->ar_btn[TURN_MAP_H].params = 0;
    opt->ar_btn[TURN_MAP_H].screen = 0;
    factory_button(opt, &close_turn, (sfIntRect){3378, 0, 30, 30},
        (sfVector2f){1870, 720});
    opt->ar_btn[CLOSE_TURN].params = 0;
    opt->ar_btn[CLOSE_TURN].screen = 0;
    seven_part_button(wndw, opt, c, m);
}
