/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** event key
*/

#include "../includes/map.h"

void key_q(maps *m)
{
    if (m->al >= 1)
        m->al -= 2;
}

void key_d(maps *m)
{
    if ((m->al < 145) && (m->al >= 0))
        m->al += 2;
}

void move_event(sfEvent event, window *wndw, maps *m, options *sprt)
{
    int tmp = 0;
    (event.key.code == sfKeyEscape) ? sfRenderWindow_close(wndw->window) : 0;
    (event.key.code == sfKeyZ) ? ++m->be : ++tmp;
    (event.key.code == sfKeyS) ? (sprt->ctrl_pressed)
    ? start_save(m) : --m->be : ++tmp;
    (event.key.code == sfKeyD) ? key_d(m) : ++tmp;
    (event.key.code == sfKeyA) ? ++m->zoom : ++tmp;
    (event.key.code == sfKeyE) ? --m->zoom : ++tmp;
    (event.key.code == sfKeyQ) ? (sprt->ctrl_pressed)
    ? start_load(m) : key_q(m) : ++tmp;
    (event.key.code == sfKeyLeft) ? m->decal_x -= 20 : ++tmp;
    (event.key.code == sfKeyRight) ? m->decal_x += 20 : ++tmp;
    (event.key.code == sfKeyDown) ? m->decal_y += 20 : ++tmp;
    (event.key.code == sfKeyUp) ? m->decal_y -= 20 : ++tmp;
    (event.key.code == sfKeySpace) ? reset_map(m) : ++tmp;
    (event.key.code == sfKeyL) ? sprt->begin = 0 : ++tmp;
    (sfKeyR == event.key.code && sprt->begin == 3) ? sprt->begin = 0 : ++tmp;
    (sfKeyM == event.key.code && sprt->begin == 0) ? sprt->begin = 3 : ++tmp;
    (event.key.code == sfKeyT) ? ++m->map_y : ++tmp;
    (event.key.code == sfKeyG) ? --m->map_y : ++tmp;
    (event.key.code == sfKeyF) ? ++m->map_x : ++tmp;
    (event.key.code == sfKeyH) ? --m->map_x : ++tmp;
}

void normal_event(redus_map re, window *wndw, options *sprt, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased)
        catch_button(wndw, sprt, event, re);
    if (event.type == sfEvtMouseButtonPressed)
        click_button(wndw, sprt, event);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wndw->window);
    if (event.type == sfEvtKeyPressed) {
        move_event(event, wndw, re.m, sprt);
        if (event.key.code == sfKeyLControl || event.key.code == sfKeyRControl)
            sprt->ctrl_pressed = 1;
    }
    if (event.type == sfEvtKeyReleased)
        if (event.key.code == sfKeyLControl || event.key.code == sfKeyRControl)
            sprt->ctrl_pressed = 0;
    mouse_event(event, re.c, re.m, sprt);
    button_mouse(wndw->window, re.m, re.c);
}

void launch_event(maps *m, cursor *c, window *wndw, options *sprt)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(wndw->window, &event))
        m->sv.is_save ? (m->sv.is_save == 1) ? save(m, event) : load_map(m, event) :
        normal_event((redus_map) {m, c}, wndw, sprt, event);
}
