/*
** EPITECH PROJECT, 2022
** world
** File description:
** world init
*/

#include "../includes/map.h"

void alloc_map(sfVector2f **map, maps *m)
{
    for (int i = 0; i < m->map_y * 2; ++i)
        map[i] = malloc(sizeof(sfVector2f) * (m->map_x * 2 + 1));
}

void alloc_3d(int **map, maps *m)
{
    for (int i = 0; i < m->map_y * 2; ++i) {
        map[i] = malloc(sizeof(int) * (m->map_x * 2 + 1));
        for (int j = 0; j < m->map_x * 2; ++j)
            map[i][j] = 0;
    }
}

void init_maps(maps *m)
{
    m->map_x = 50;
    m->map_y = 50;
    m->td_map = malloc(sizeof(int **) * (m->map_y * 2+ 1));
    m->map = malloc(sizeof(sfVector2f *) * (m->map_y * 2 + 1));;
    m->water_map = malloc(sizeof(sfVector2f *) * (m->map_y * 2) + 1);
    alloc_3d(m->td_map , m);
    alloc_map(m->map, m);
    alloc_map(m->water_map, m);
    m->al = 0;
    m->be = 0;
    m->zoom = 50;
    m->decal_x = m->map_x / 50 + 700;
    m->decal_y = m->map_y / 50 + 700;
}

void init_cursor(cursor *c)
{
    c->t = sfTexture_create(WIDTH, HEIGHT);
    c->framebuffer = malloc(sizeof(sfUint8) * HEIGHT * WIDTH * 4 * 8);
    c->s = sfSprite_create();
    c->radius = 100;
    c->style = 0;
    sfSprite_setTexture(c->s, c->t, sfTrue);
}
