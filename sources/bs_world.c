/*
** EPITECH PROJECT, 2022
** world
** File description:
** bs
*/

#include "../includes/map.h"

void decal_map(maps *m, int x, int y, angle_bs aglb)
{
    m->water_map[y][x].y = sin(aglb.angle_b) *
    (aglb.tmp_y + sin(aglb.angle_b) *
    (aglb.tmp_x - aglb.back_x * sin(aglb.ang_h)));
    m->water_map[y][x].x = cos(aglb.angle_a) *
    (aglb.tmp_x - cos(aglb.angle_a) * aglb.tmp_y);
    m->map[y][x].x *= m->zoom;
    m->map[y][x].y *= m->zoom;
    m->map[y][x].x += m->decal_x;
    m->map[y][x].y += m->decal_y;
    m->water_map[y][x].x *= m->zoom;
    m->water_map[y][x].y *= m->zoom;
    m->water_map[y][x].x += m->decal_x;
    m->water_map[y][x].y += m->decal_y;
}

void project_iso_point(int x, int y, int z, maps *m)
{
    angle_bs aglb = {m->al * (M_PI / 180), m->be * (M_PI / 180)
    , 35 * (M_PI / 180), 45 * (M_PI / 180), 0, 0, 0, 0};
    x -= m->map_x / 2;
    y -= m->map_y / 2;
    aglb.tmp_x = x * cos(aglb.angle) - y * sin(aglb.angle);
    aglb.tmp_y = y * cos(aglb.angle) + x * sin(aglb.angle);
    aglb.back_x = aglb.tmp_x;
    aglb.tmp_x = aglb.back_x * cos(aglb.ang_h) - z * sin(aglb.ang_h);
    aglb.tmp_z = z * cos(aglb.ang_h) + aglb.back_x * sin(aglb.ang_h);
    x += m->map_x / 2;
    y += m->map_y / 2;
    m->map[y][x].y = sin(aglb.angle_b) *
    (aglb.tmp_y + sin(aglb.angle_b) * (aglb.tmp_x - aglb.tmp_z));
    m->map[y][x].x = cos(aglb.angle_a) *
    (aglb.tmp_x - cos(aglb.angle_a) * aglb.tmp_y);
    decal_map(m, x, y, aglb);
}

void create_2d_map(maps *m)
{
    for (int i = 0; i < m->map_y; ++i)
        for (int j = 0; j < m->map_x; ++j)
            project_iso_point(j, i, m->td_map[i][j], m);
}

void create_line(int i, int j, maps *m, sfRenderWindow *wnd)
{
    sfColor color = biggest(j, i, m);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {m->map[i][j], color};
    sfVertex vertex2 = {m->map[i + 1][j + 1], color};
    sfVertex vertex3 = {m->map[i + 1][j], color};
    sfVertex vertex4 = {m->map[i][j + 1],  color};

    draw_water(i, j, m, wnd);
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(wnd, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}

void draw_2d_map(sfRenderWindow *wnd, maps *m)
{
    create_2d_map(m);
    if ((m->al >= 55) && (m->al < 110))
        draw_five_five(m, wnd);
    if ((m->al >= 0) && (m->al < 55))
        draw_zero(m, wnd);
    if ((m->al >= 110) && (m->al < 150))
        draw_one_one_zero(m, wnd);
}
