/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** first
*/

#include "../includes/map.h"

void reset_map(maps *m)
{
    for (int y = 0; y < m->map_y; ++y)
        for (int x = 0; x < m->map_x; ++x)
            m->td_map[y][x] = 0;
}

void my_world(sfRenderWindow *wnd, maps *m, cursor *c)
{
    sfRenderWindow_clear(wnd, sfBlack);
    draw_2d_map(wnd, m);
    move_cursor(c, wnd, m);
}
