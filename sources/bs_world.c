/*
** EPITECH PROJECT, 2022
** world
** File description:
** bs
*/

#include "../includes/map.h"

void decal_map(maps *m, int x, int y)
{
    m->map[y][x].x *= m->zoom;
    m->map[y][x].y *= m->zoom;
    m->map[y][x].x += m->decal_x;
    m->map[y][x].y += m->decal_y;
}
void project_iso_point(int x, int y, int z, maps *m)
{
    float angle = m->al * (M_PI / 180);
    float ang_h = m->be * (M_PI / 180);
    float angle_b = 35 * (M_PI / 180);
    float angle_a = 45 * (M_PI / 180);
    float tmp_x = 0;
    float tmp_y = 0;
    float tmp_z = z;
    float back_x = 0;
    x -= MAP_X / 2;
    y -= MAP_Y / 2;
    tmp_x = x * cos(angle) - y * sin(angle);
    tmp_y = y * cos(angle) + x * sin(angle);
    back_x = tmp_x;
    tmp_x = back_x * cos(ang_h) - z * sin(ang_h);
    tmp_z = z * cos(ang_h) + back_x * sin(ang_h);
    x += MAP_X / 2;
    y += MAP_Y / 2;
    m->map[y][x].y = sin(angle_b) * (tmp_y + sin(angle_b) * (tmp_x - tmp_z));
    m->map[y][x].x = cos(angle_a) * (tmp_x - cos(angle_a) * tmp_y);
    decal_map(m, x, y);
}

void create_2d_map(maps *m)
{
    for (int i = 0; i < MAP_Y; ++i)
        for (int j = 0; j < MAP_X; ++j)
            project_iso_point(j, i, m->td_map[i][j], m);
}

int is_biggest(int first, int second, int third, int four)
{
    if (first >= second && first >= third && first >= four)
        return 1;
    return 0;
}

sfColor biggest(int x, int y, maps *m)
{
    int one  = m->td_map[y][x];
    int two  = m->td_map[y + 1][x];
    int three  = m->td_map[y][x + 1];
    int four  = m->td_map[y + 1][x + 1];
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

void create_line(int i, int j, maps *m, sfRenderWindow *wnd)
{
    sfColor color = biggest(j, i, m);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {m->map[i][j], color};
    sfVertex vertex2 = {m->map[i + 1][j + 1], color};
    sfVertex vertex3 = {m->map[i + 1][j], color};
    sfVertex vertex4 = {m->map[i][j + 1],  color};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(wnd, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}

void water_iso_point(maps *m, int i, sfVector2f *tmp, tmp_water w)
{
    float angle = m->al * (M_PI / 180);
    float ang_h = m->be * (M_PI / 180);
    float angle_b = 35 * (M_PI / 180);
    float angle_a = 45 * (M_PI / 180);

    w.x -= MAP_X / 2;
    w.y -= MAP_Y / 2;
    w.tmp_x = w.x * cos(angle) - w.y * sin(angle);
    w.tmp_y = w.y * cos(angle) + w.x * sin(angle);
    w.back_x = w.tmp_x;
    w.tmp_x = w.back_x * cos(ang_h) - w.z * sin(ang_h);
    w.tmp_z = w.z * cos(ang_h) + w.back_x * sin(ang_h);
    w.x += MAP_X / 2;
    w.y += MAP_Y / 2;
    tmp[i].y = sin(angle_b) * (w.tmp_y + sin(angle_b) * (w.tmp_x - w.tmp_z));
    tmp[i].x = cos(angle_a) * (w.tmp_x - cos(angle_a) * w.tmp_y);
    tmp[i].y *= m->zoom;
    tmp[i].x *= m->zoom;
    tmp[i].x += m->decal_x;
    tmp[i].y += m->decal_y;
}

void draw_water(sfRenderWindow *wnd, sfVector2f *tmp)
{
    sfColor color = sfColor_fromRGBA(28 , 120, 255,120);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {tmp[0], color};
    sfVertex vertex2 = {tmp[1], color};
    sfVertex vertex3 = {tmp[2], color};
    sfVertex vertex4 = {tmp[3],  color};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    sfRenderWindow_drawVertexArray(wnd, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}

void launch_water(maps *m , sfRenderWindow *wnd)
{
    sfVector2f *tmp = malloc(sizeof(sfVector2f) * 5);
    water_iso_point(m, 0, tmp, (tmp_water) {0, 0, 0, 0, 0, 0, 0});
    water_iso_point(m, 1, tmp, (tmp_water) {MAP_X, MAP_Y, 0, 0, 0, 0, 0});
    water_iso_point(m, 2, tmp, (tmp_water) {0, MAP_Y, 0, 0, 0, 0, 0});
    water_iso_point(m, 3, tmp, (tmp_water) {MAP_X, 0, 0, 0, 0, 0, 0});
    draw_water(wnd, tmp);
}

void draw_2d_map(sfRenderWindow *wnd, maps *m)
{
    create_2d_map(m);
    launch_water(m, wnd);
    if ((m->al >= 55) && (m->al < 110))
        draw_five_five(m, wnd);
    if ((m->al >= 0) && (m->al < 55))
        draw_zero(m, wnd);
    if ((m->al >= 110) && (m->al < 150))
        draw_one_one_zero(m, wnd);
}
