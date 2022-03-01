/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** button gestion
*/

#include "../includes/map.h"

void touch_button(window *wndw, options *opt, int i, sfVector2i pos)
{
    sfVector2f yes = sfSprite_getPosition(opt->ar_btn[i].sprt);
    sfIntRect tmp = {yes.x, yes.y, opt->ar_btn[i].place.width,
    opt->ar_btn[i].place.height};
    sfIntRect new = {opt->ar_btn[i].place.left, opt->ar_btn[i].place.height,
    opt->ar_btn[i].place.width, opt->ar_btn[i].place.height};
    if (sfIntRect_contains(&tmp, pos.x, pos.y) && opt->ar_btn[i].event != 3) {
        sfSprite_setTextureRect(opt->ar_btn[i].sprt, new);
        opt->ar_btn[i].event = 0;
        } else if (opt->ar_btn[i].event != 3)
        sfSprite_setTextureRect(opt->ar_btn[i].sprt, opt->ar_btn[i].place);
    if (opt->ar_btn[i].screen == opt->begin && opt->ar_btn[i].params)
        sfRenderWindow_drawSprite(wndw->window, opt->ar_btn[i].sprt, NULL);
}

void is_touched_button(window *wndw, options *opt)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    for (int i = 0; i < opt->len_button; ++i)
        touch_button(wndw, opt, i, pos);
}

void factory_button(options *opt, ptr_f fc, sfIntRect old, sfVector2f pos)
{
    button btn;
    btn.sprt = sfSprite_create();
    btn.place = old;
    btn.pos = pos;
    btn.launch = fc;
    btn.event = 0;
    sfSprite_setTexture(btn.sprt, opt->t, sfTrue);
    sfSprite_setTextureRect(btn.sprt, old);
    sfSprite_setPosition(btn.sprt, pos);
    opt->ar_btn[opt->len_button] = btn;
    ++opt->len_button;
}

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

int open_p(window *wndw, options *opt, cursor *c, maps *m)
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
    return 0;
}

int open_params(window *wndw, options *opt, cursor *c, maps *m)
{
    opt->params = 1;
    opt->mv = 1;
    return 0;
}

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
    m->decal_x -= 50;
    return 0;
}

int go_right(window *wndw, options *opt, cursor *c, maps *m)
{
    m->decal_x += 50;
    return 0;
}

int go_down(window *wndw, options *opt, cursor *c, maps *m)
{
    m->decal_y += 50;
    return 0;
}

int go_up(window *wndw, options *opt, cursor *c, maps *m)
{
    m->decal_y -= 50;
    return 0;
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
    factory_button(opt, &open_params, (sfIntRect){1347, 0, 77, 24},
        (sfVector2f){201, 62});
    opt->ar_btn[OPEN_PARAMS].params = 1;
    opt->ar_btn[OPEN_PARAMS].screen = 0;
    factory_button(opt, &go_home, (sfIntRect) {1501, 0, 200, 40},
                   (sfVector2f) {140, 200});
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
    factory_button(opt, &open_view, (sfIntRect){2501, 0, 200, 40},
        (sfVector2f){140, 300});
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
    factory_button(opt, &go_up, (sfIntRect){1961, 0, 60, 60},
        (sfVector2f){1760, 920});
    opt->ar_btn[FLECHE_HAUT].params = 0;
    opt->ar_btn[FLECHE_HAUT].screen = 0;
    factory_button(opt, &close_view, (sfIntRect){3378, 0, 30, 30},
        (sfVector2f){1870, 920});
    opt->ar_btn[CLOSE_VIEW].params = 0;
    opt->ar_btn[CLOSE_VIEW].screen = 0;
    factory_button(opt, &open_turn, (sfIntRect){2778, 0, 200, 40},
        (sfVector2f){140, 360});
    opt->ar_btn[OPEN_TURN].params = 0;
    opt->ar_btn[OPEN_TURN].screen = 0;
    factory_button(opt, &close_params, (sfIntRect){2261, 0, 60, 60},
        (sfVector2f){1680, 800});
    opt->ar_btn[TURN_MAP_L].params = 0;
    opt->ar_btn[TURN_MAP_L].screen = 0;
    factory_button(opt, &close_params, (sfIntRect){2441, 0, 60, 60},
        (sfVector2f){1760, 800});
    opt->ar_btn[TURN_MAP_B].params = 0;
    opt->ar_btn[TURN_MAP_B].screen = 0;
    factory_button(opt, &close_params, (sfIntRect){2321, 0, 60, 60},
        (sfVector2f){1840, 800});
    opt->ar_btn[TURN_MAP_R].params = 0;
    opt->ar_btn[TURN_MAP_R].screen = 0;
    factory_button(opt, &close_params, (sfIntRect){2381, 0, 60, 60},
        (sfVector2f){1760, 720});
    opt->ar_btn[TURN_MAP_H].params = 0;
    opt->ar_btn[TURN_MAP_H].screen = 0;
    factory_button(opt, &close_turn, (sfIntRect){3378, 0, 30, 30},
        (sfVector2f){1870, 720});
    opt->ar_btn[CLOSE_TURN].params = 0;
    opt->ar_btn[CLOSE_TURN].screen = 0;
    factory_button(opt, &open_zoom, (sfIntRect){2978, 0, 200, 40},
        (sfVector2f){140, 420});
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
    factory_button(opt, &reset_button, (sfIntRect){3178, 0, 200, 40},
        (sfVector2f){140, 480});
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
}

void linked_button(options *opt, window *wndw, cursor *c, maps *m)
{
    opt->t = sfTexture_createFromFile("ressources/buttons.png", NULL);
    opt->ar_btn = malloc(sizeof(button) * 30);
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

void move_rect_pressed(options *opt, int i)
{
    sfIntRect new = {opt->ar_btn[i].place.left, opt->ar_btn[i].place.height * 2,
    opt->ar_btn[i].place.width, opt->ar_btn[i].place.height};
    sfSprite_setTextureRect(opt->ar_btn[i].sprt, new);
    opt->ar_btn[i].event = 3;
}

void catch_button(window *wndw, options *opt, sfEvent event, cursor *c, maps *m)
{
    for (int i = 0; i < opt->len_button; ++i) {
        if (opt->ar_btn[i].params == 1 && ((event.mouseButton.x >= opt->ar_btn[i].pos.x) &&
        (event.mouseButton.x <= (opt->ar_btn[i].pos.x +
        opt->ar_btn[i].place.width))) && ((event.mouseButton.y >=
        opt->ar_btn[i].pos.y) && (event.mouseButton.y <=
        (opt->ar_btn[i].pos.y + opt->ar_btn[i].place.height) &&
        opt->ar_btn[i].screen == opt->begin)))
            (*(opt->ar_btn[i].launch))(wndw, opt, c, m);
        opt->ar_btn[i].event = 0;
    }
}

void click_button(window *wndw, options *opt, sfEvent event)
{
        for (int i = 0; i < opt->len_button; ++i) {
        if (((event.mouseButton.x >= opt->ar_btn[i].pos.x) &&
        (event.mouseButton.x <= (opt->ar_btn[i].pos.x +
        opt->ar_btn[i].place.width))) && ((event.mouseButton.y >=
        opt->ar_btn[i].pos.y) && (event.mouseButton.y <=
        (opt->ar_btn[i].pos.y + opt->ar_btn[i].place.height) &&
        opt->ar_btn[i].screen == opt->begin)))
            move_rect_pressed(opt, i);
    }
}
