/*
** EPITECH PROJECT, 2022
** world
** File description:
** cursor gestion
*/

#include "../includes/map.h"

void clean_for(cursor *c)
{
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            put_pixel(i, j, sfTransparent, c->framebuffer);
}

void move_other_cursor(cursor *c, sfRenderWindow *wnd, maps *m)
{
    int tmp_x = sfMouse_getPosition(NULL).x;
    int tmp_y = sfMouse_getPosition(NULL).y;
    clean_for(c);
    if (((tmp_x - c->radius) > 0) && ((tmp_y - c->radius) > 0))
        draw_empty_circle(sfWhite, c->framebuffer, (circle)
        {tmp_y, tmp_x, c->radius});
    sfTexture_updateFromPixels(c->t, c->framebuffer, WIDTH, HEIGHT, 0, 0);
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
        draw_circle(sfWhite, c->framebuffer, (circle) {y, x, c->radius});
    sfTexture_updateFromPixels(c->t, c->framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(wnd, c->s, NULL);
    return 0;
}
