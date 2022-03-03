/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** first
*/

#include "../includes/map.h"

void mouse_event(sfEvent event, cursor *c, maps *m)
{
    if (event.type == sfEvtMouseWheelScrolled) {
        if (event.mouseWheelScroll.delta == 1)
            !c->ctrl_pressed ? ++c->radius : ++m->zoom;
        else
            !c->ctrl_pressed ? (c->radius > 10 ? --c->radius : (c->radius = c->radius)) : (m->zoom > 10 ? --m->zoom : (m->zoom = m->zoom));
    }
}

void reset_map(maps *m)
{
    for (int y = 0; y < m->map_y; ++y)
        for (int x = 0; x < m->map_x; ++x)
            m->td_map[y][x] = 0;
}

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
    (event.key.code == sfKeyEscape) ? sfRenderWindow_close(wndw->window) : ++tmp;
    (event.key.code == sfKeyZ) ? ++m->be : ++tmp;
    (event.key.code == sfKeyS) ? --m->be : ++tmp;
    (event.key.code == sfKeyD) ? key_d(m) : ++tmp;
    (event.key.code == sfKeyA) ? ++m->zoom : ++tmp;
    (event.key.code == sfKeyE) ? --m->zoom : ++tmp;
    (event.key.code == sfKeyQ) ? key_q(m) : ++tmp;
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

void incidence(maps *m, int y, int x, mouse_c p)
{
    int tmp = 0;
    if (y + 1 < m->map_y && x + 1 < m->map_x && x > 0 && y > 0) {
        tmp = m->td_map[y][x] - 8;
        if (m->td_map[y + 1][x] < tmp) {
            m->td_map[y + 1][x] += p.delta;
            incidence(m, y + 1, x, p);
        }
        if (m->td_map[y][x + 1] < tmp) {
            m->td_map[y][x + 1] += p.delta;
            incidence(m, y, x + 1, p);
        }
        if (m->td_map[y][x - 1] < tmp) {
            m->td_map[y][x - 1] += p.delta;
            incidence(m, y, x - 1, p);
        }
        if (m->td_map[y - 1][x] < tmp) {
            m->td_map[y - 1][x] += p.delta;
            incidence(m, y - 1, x, p);
        }
    }
}

void check_mouse_pos(maps *m, int y, int x, mouse_c p)
{
    if ((m->map[y][x].x <= (p.x + p.radius)) && (m->map[y][x + 1].x >= (p.x - p.radius)) &&
    ((m->map[y][x].y <= (p.y + p.radius)) && (m->map[y + 1][x].y >= (p.y - p.radius)))) {
        m->td_map[y][x] += p.delta;
        incidence(m, y, x, p);
    }
}

void go_in_array(maps *m, mouse_c p)
{
    for (int y = 0; y < m->map_y - 2; ++y)
        for (int x = 0; x < m->map_x - 2; ++x)
            check_mouse_pos(m, y, x, p);
}

void button_mouse(sfRenderWindow *window, maps *m, cursor *c)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft) && !c->is_button)
        go_in_array(m, (mouse_c) {pos.x, pos.y, 1, c->radius / 2});
    if (sfMouse_isButtonPressed(sfMouseRight) && !c->is_button)
        go_in_array(m, (mouse_c) {pos.x, pos.y, - 1, c->radius / 2});
    if (sfMouse_isButtonPressed(sfMouseMiddle))
        c->style = c->style ? 0 : 1;
}

void launch_event(maps *m, cursor *c, window *wndw, options *sprt)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(wndw->window, &event)) {
        if (event.type == sfEvtMouseButtonReleased)
            catch_button(wndw, sprt, event, c, m);
        if (event.type == sfEvtMouseButtonPressed)
            click_button(wndw, sprt, event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(wndw->window);
        if (event.type == sfEvtKeyPressed) {
            move_event(event, wndw, m, sprt);
            if (event.key.code == sfKeyLControl)
                c->ctrl_pressed = 1;
        }
        if (event.type == sfEvtKeyReleased)
            if (event.key.code == sfKeyLControl)
                c->ctrl_pressed = 0;
        mouse_event(event, c, m);
        button_mouse(wndw->window, m, c);
    }
}

int diff_color(maps *m, int i, int j, int max)
{
    int tmp = (3 * (j % 2)) + (m->td_map[i][j] / 2) + (3 * (i % 2));
    return tmp <= max ? tmp : max;
}

sfColor choose_color(int i, int j, maps *m)
{
    if (m->td_map[i][j] > 5 && m->td_map[i][j] < 50)
        return sfColor_fromRGB(105 + diff_color(m, i, j, 200), 105 + diff_color(m, i, j, 200), 105 + diff_color(m, i, j, 200));
    if (m->td_map[i][j] >= 50)
        return sfColor_fromRGB(200 + diff_color(m, i, j, 54), 200 + diff_color(m, i, j, 54), 200 + diff_color(m, i, j, 54));
    return sfColor_fromRGB(91, 139 + diff_color(m, i, j, 255), 50);
}

void my_world(sfRenderWindow *wnd, maps *m, cursor *c)
{
    sfRenderWindow_clear(wnd, sfBlack);
    draw_2d_map(wnd, m);
    move_cursor(c, wnd, m);
}
