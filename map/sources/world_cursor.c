/*
** EPITECH PROJECT, 2022
** world
** File description:
** cursor gestion
*/

#include "../includes/world.h"

void put_pixel(int x, int y, sfColor color, sfUint8 *framebuffer)
{
    *(sfColor * )(4 * (x * width + y) + framebuffer) = color;
}

void draw_circle(sfColor color, sfUint8 *frambuffer, int x, int y, int radius)
{
    for (int i = x - radius; i <= x + radius + 1; ++i)
        for (int j = y - radius; j <= y + radius + 1; ++j) {
            if ((sqrt((pow(i - x, 2) + pow(j - y, 2))) <= radius) && (j % 8 == 0) && (i % 8 == 0))
                put_pixel(i, j, color, frambuffer);
        }
}

int verif_circle(int i, int j, int x, int y)
{
    int res = (pow((i - x), 2) + pow((j - y), 2));
    if (res < 0)
        res = -res;
    return sqrt(res);
}
               
void draw_empty_circle(sfColor color, sfUint8 *frambuffer, int x, int y, int radius)
{
    for (int i = x - radius; i <= x + radius + 1; ++i)
        for (int j = y - radius; j <= y + radius + 1; ++j) {
            if ((verif_circle(i, j, x, y) == radius) ||
                (verif_circle(i, j, x, y) == radius - 1) ||
                (verif_circle(i, j, x, y) == radius + 1))
                put_pixel(i, j, color, frambuffer);
        }
}

void clean_for(cursor *c)
{
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            put_pixel(i, j, sfTransparent, c->framebuffer);
}

void move_other_cursor(cursor *c, sfRenderWindow *wnd, maps *m)
{
    int tmp_x = sfMouse_getPosition(NULL).x;
    int tmp_y = sfMouse_getPosition(NULL).y;
    clean_for(c);
    if (((tmp_x - c->radius) > 0) && ((tmp_y - c->radius) > 0))
        draw_empty_circle(sfWhite, c->framebuffer, tmp_y, tmp_x, c->radius);
    sfTexture_updateFromPixels(c->t, c->framebuffer, width, height, 0, 0);
    sfRenderWindow_drawSprite(wnd, c->s, NULL);
}

int move_cursor(cursor *c, sfRenderWindow *wnd, maps *m)
{
    int x = 0;
    int y = 0;
    if (c->style) {
        move_other_cursor(c, wnd, m);
        return 1;
    }
    x = sfMouse_getPosition(NULL).x;
    y = sfMouse_getPosition(NULL).y;
    clean_for(c);
    if (((x - c->radius) > 0) && ((y - c->radius) > 0))
        draw_circle(sfWhite, c->framebuffer, y, x, c->radius);
    sfTexture_updateFromPixels(c->t, c->framebuffer, width, height, 0, 0);
    sfRenderWindow_drawSprite(wnd, c->s, NULL);
    return 0;
}
