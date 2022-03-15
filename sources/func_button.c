/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** part_linked_b.c
*/

#include "../includes/map.h"

void fifth_part_button(window *wndw, options *opt, cursor *c, maps *m)
{
    factory_button(opt, &go_up, (sfIntRect){1961, 0, 60, 60},
        (sfVector2f){1760, 920});
    opt->ar_btn[FLECHE_HAUT].params = 0;
    opt->ar_btn[FLECHE_HAUT].screen = 0;
    factory_button(opt, &close_view, (sfIntRect){3378, 0, 30, 30},
        (sfVector2f){1870, 920});
    opt->ar_btn[CLOSE_VIEW].params = 0;
    opt->ar_btn[CLOSE_VIEW].screen = 0;
    factory_button(opt, &open_turn, (sfIntRect){2778, 0, 200, 40},
        (sfVector2f){140, 370});
    opt->ar_btn[OPEN_TURN].params = 0;
    opt->ar_btn[OPEN_TURN].screen = 0;
    factory_button(opt, &turn_left, (sfIntRect){2261, 0, 60, 60},
        (sfVector2f){1680, 800});
    opt->ar_btn[TURN_MAP_L].params = 0;
    opt->ar_btn[TURN_MAP_L].screen = 0;
    sixth_part_button(wndw, opt, c, m);
}

void fourth_part_button(window *wndw, options *opt, cursor *c, maps *m)
{
    factory_button(opt, &open_view, (sfIntRect){2501, 0, 200, 40},
        (sfVector2f){140, 310});
    opt->ar_btn[OPEN_CHG_VIEW].params = 0;
    opt->ar_btn[OPEN_CHG_VIEW].screen = 0;
    factory_button(opt, &go_left, (sfIntRect){2021, 0, 60, 60},
        (sfVector2f){1680, 1000});
    opt->ar_btn[FLECHE_GAUCHE].params = 0;
    opt->ar_btn[FLECHE_GAUCHE].screen = 0;
    factory_button(opt, &go_down, (sfIntRect){2081, 0, 60, 60},
        (sfVector2f){1760, 1000});
    opt->ar_btn[FLECHE_BAS].params = 0;
    opt->ar_btn[FLECHE_BAS].screen = 0;
    factory_button(opt, &go_right, (sfIntRect){1901, 0, 60, 60},
        (sfVector2f){1840, 1000});
    opt->ar_btn[FLECHE_DROITE].params = 0;
    opt->ar_btn[FLECHE_DROITE].screen = 0;
    fifth_part_button(wndw, opt, c, m);
}

void third_part_button(window *wndw, options *opt, cursor *c, maps *m)
{
    factory_button(opt, &open_params, (sfIntRect){1347, 0, 77, 24},
        (sfVector2f){201, 62});
    opt->ar_btn[OPEN_PARAMS].params = 1;
    opt->ar_btn[OPEN_PARAMS].screen = 0;
    factory_button(opt, &go_home, (sfIntRect) {1501, 0, 200, 40},
                   (sfVector2f) {140, 190});
    opt->ar_btn[SAVE_FILE].params = 0;
    opt->ar_btn[SAVE_FILE].screen = 0;
    factory_button(opt, &quit_button, (sfIntRect) {1701, 0, 200, 40},
                   (sfVector2f) {140, 900});
    opt->ar_btn[LOG_OUT].params = 0;
    opt->ar_btn[LOG_OUT].screen = 0;
    factory_button(opt, &close_params, (sfIntRect){1424, 0, 77, 24},
        (sfVector2f){201, 979});
    opt->ar_btn[CLOSE_PARAMS].params = 0;
    opt->ar_btn[CLOSE_PARAMS].screen = 0;
    fourth_part_button(wndw, opt, c, m);
}

void second_part_button(window *wndw, options *opt, cursor *c, maps *m)
{
    factory_button(opt, &open_menu, (sfIntRect){477, 0, 200, 40},
                   (sfVector2f){25, 10});
    opt->ar_btn[OPEN_MENU].params = 1;
    opt->ar_btn[OPEN_MENU].screen = 0;
    factory_button(opt, &quit_button, (sfIntRect){200, 0, 200, 74},
        (sfVector2f){700, 580});
    opt->ar_btn[ESCAPE_MENU].params = 1;
    opt->ar_btn[ESCAPE_MENU].screen = 3;
    factory_button(opt, &resume_game, (sfIntRect){677, 0, 200, 74},
        (sfVector2f){1015, 580});
    opt->ar_btn[RESUME_MENU].params = 1;
    opt->ar_btn[RESUME_MENU].screen = 3;
    factory_button(opt, &go_home, (sfIntRect){877, 0, 200, 74},
        (sfVector2f){860, 500});
    opt->ar_btn[HOME_MENU].params = 1;
    opt->ar_btn[HOME_MENU].screen = 3;
    third_part_button(wndw, opt, c, m);
}

void linked_button(options *opt, window *wndw, cursor *c, maps *m)
{
    opt->t = sfTexture_createFromFile("ressources/buttons.png", NULL);
    opt->ar_btn = malloc(sizeof(button) * 37);
    opt->len_button = 0;
    factory_button(opt, &continue_button, (sfIntRect){0, 0, 200, 74},
                   (sfVector2f){865, 700});
    opt->ar_btn[ESCAPE_PROG].params = 1;
    opt->ar_btn[ESCAPE_PROG].screen = 1;
    factory_button(opt, &quit_button, (sfIntRect){200, 0, 200, 74},
                   (sfVector2f){865, 800});
    opt->ar_btn[CONTINUE].params = 1;
    opt->ar_btn[CONTINUE].screen = 1;
    factory_button(opt, &quit_button, (sfIntRect){400, 0, 77, 24},
                   (sfVector2f){1830, 20});
    opt->ar_btn[ESCAPE_PRCP].params = 1;
    opt->ar_btn[ESCAPE_PRCP].screen = 0;
    second_part_button(wndw, opt, c, m);
}
