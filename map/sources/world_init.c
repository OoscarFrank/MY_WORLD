/*
** EPITECH PROJECT, 2022
** world
** File description:
** world init
*/

#include "../includes/world.h"

void alloc_map(sfVector2f **map)
{
    for (int i = 0; i < MAP_Y; ++i)
        map[i] = malloc(sizeof(sfVector2f) * (MAP_X + 1));
}

void alloc_3d(int **map)
{
    for (int i = 0; i < MAP_Y; ++i) {
        map[i] = malloc(sizeof(int) * (MAP_X + 1));
        for (int j = 0; j < MAP_X; ++j)
            map[i][j] = 0;
    }
}

void init_maps(maps *m)
{
    sfVector2f **od_map = malloc(sizeof(sfVector2f *) * (MAP_Y + 1));
    int **three_d = malloc(sizeof(int **) * (MAP_Y + 1));
    alloc_3d(three_d);
    alloc_map(od_map);
    m->td_map = three_d;
    m->map = od_map;
    m->al = 0;
    m->be = 0;
    m->zoom = 50;
    m->decal_x = MAP_X * 50;
    m->decal_y = MAP_Y * 25;
}

void init_cursor(cursor *c)
{
    c->t = sfTexture_create(width, height);
    c->framebuffer = malloc(sizeof(sfUint8) * height * width * 4 * 8);
    c->s = sfSprite_create();
    c->radius = 100;
    c->style = 0;
    sfSprite_setTexture(c->s, c->t, sfTrue);
}
