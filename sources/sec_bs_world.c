/*
** EPITECH PROJECT, 2022
** world
** File description:
** bs
*/

#include "../includes/map.h"

int is_biggest(int first, int second, int third, int four)
{
    if (first >= second && first >= third && first >= four)
        return 1;
    return 0;
}

sfColor biggest(int x, int y, maps *m)
{
    int one = m->td_map[y][x];
    int two = m->td_map[y + 1][x];
    int three = m->td_map[y][x + 1];
    int four = m->td_map[y + 1][x + 1];
    if (is_biggest(one, two, three, four))
        return choose_color(y, x, m);
    if (is_biggest(two, one, three, four))
        return choose_color(y + 1, x, m);
    if (is_biggest(three, two, one, four))
        return choose_color(y, x + 1, m);
    if (is_biggest(four, two, three, one))
        return choose_color(y + 1, x + 1, m);
    return choose_color(y, x, m);
}

void draw_water(int i, int j, maps *m, sfRenderWindow *wnd)
{
    sfColor color = sfColor_fromRGBA(0, 117, 219, 130);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {m->water_map[i][j], color};
    sfVertex vertex2 = {m->water_map[i + 1][j + 1], color};
    sfVertex vertex3 = {m->water_map[i + 1][j], color};
    sfVertex vertex4 = {m->water_map[i][j + 1],  color};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(wnd, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}
