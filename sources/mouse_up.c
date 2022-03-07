/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** move up
*/

#include "../includes/map.h"

void incidence(maps *m, int y, int x, mouse_c p)
{
    int tmp = 0;
    if (y + 3 < m->map_y && x + 3 < m->map_x && x > 2 && y > 2) {
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
    if ((((m->map[y][x].y <= (p.y + p.radius)) && (m->map[y + 1][x].y >= (p.y - p.radius)))) &&
        ((m->map[y][x].x <= (p.x + p.radius)) && (m->map[y][x + 1].x >= (p.x - p.radius)))) {
        m->td_map[y][x] += p.delta;
        incidence(m, y, x, p);
    }
}

void go_in_array(maps *m, mouse_c p)
{
    for (int i = 1; i < m->map_y - 3; ++i)
        for (int j = 1; j < m->map_x - 3; ++j)
            check_mouse_pos(m, i, j, p);
}

void button_mouse(sfRenderWindow *window, maps *m, cursor *c)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        go_in_array(m, (mouse_c) {pos.x, pos.y, 1, c->radius / 2});
    if (sfMouse_isButtonPressed(sfMouseRight))
        go_in_array(m, (mouse_c) {pos.x, pos.y, - 1, c->radius / 2});
    if (sfMouse_isButtonPressed(sfMouseMiddle))
        c->style = c->style ? 0 : 1;
}

void mouse_event(sfEvent event, cursor *c, maps *m, options *sprt)
{
    if (event.type == sfEvtMouseWheelScrolled) {
        if (event.mouseWheelScroll.delta == 1)
            !sprt->ctrl_pressed ? ++c->radius : ++m->zoom;
        else
            !sprt->ctrl_pressed ? (c->radius > 10 ? --c->radius : (c->radius = c->radius))
            : (m->zoom > 10 ? --m->zoom : (m->zoom = m->zoom));
    }
}
