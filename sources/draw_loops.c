/*
** EPITECH PROJECT, 2022
** world
** File description:
** loop for draw
*/

#include "../includes/map.h"

void draw_zero(maps *m, sfRenderWindow *wnd)
{
    int tmp_y = MAP_Y;
    int tmp_x = MAP_X;
    for (int i = 0; i < tmp_y - 1; ++i)
        for (int j = 0; j < tmp_x - 1; ++j)
            create_line(i, j, m, wnd);
}

void draw_five_five(maps *m, sfRenderWindow *wnd)
{
    int tmp_y = MAP_Y;
    int tmp_x = MAP_X;
    for (int i = tmp_y - 2; i >= 0; --i)
        for (int j = 0; j < tmp_x - 1; ++j)
            create_line(i, j, m, wnd);
}

void draw_one_one_zero(maps *m, sfRenderWindow *wnd)
{
    int tmp_y = MAP_Y;
    int tmp_x = MAP_X;
    for (int i = tmp_y - 2; i >= 0; --i)
        for (int j = tmp_x - 2; j >= 0; --j)
            create_line(i, j, m, wnd);
}