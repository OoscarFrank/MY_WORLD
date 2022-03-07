/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** changing colors
*/

#include "../includes/map.h"

int diff_color(maps *m, int i, int j, int max)
{
    int tmp = (3 * (j % 2)) + (m->td_map[i][j] / 2) + (3 * (i % 2));
    return tmp <= max ? tmp : max;
}

sfColor choose_color(int i, int j, maps *m)
{
    if (m->td_map[i][j] > 10 && m->td_map[i][j] < 30)
        return sfColor_fromRGB(105 + diff_color(m, i, j, 120), 78 +
        diff_color(m, i, j, 98), 43 + diff_color(m, i, j, 63));
    if (m->td_map[i][j] >= 30 && m->td_map[i][j] < 70)
        return sfColor_fromRGB(105 + diff_color(m, i, j, 200), 105 +
        diff_color(m, i, j, 200), 105 + diff_color(m, i, j, 200));
    if (m->td_map[i][j] >= 70)
        return sfColor_fromRGB(200 + diff_color(m, i, j, 54), 200 +
        diff_color(m, i, j, 54), 200 + diff_color(m, i, j, 54));
    return sfColor_fromRGB(91, 139 + diff_color(m, i, j, 255), 50);
}
