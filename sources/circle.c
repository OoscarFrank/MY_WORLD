/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** circle
*/

#include "../includes/map.h"

void put_pixel(int x, int y, sfColor color, sfUint8 *framebuffer)
{
    *(sfColor * )(4 * (x * WIDTH + y) + framebuffer) = color;
}

void draw_circle(sfColor color, sfUint8 *frambuffer, circle crl)
{
    int verif = 0;
    for (int i = crl.x - crl.radius; i <= crl.x + crl.radius + 1; ++i)
        for (int j = crl.y - crl.radius; j <= crl.y + crl.radius + 1; ++j)
            ((sqrt((pow(i - crl.x, 2) + pow(j - crl.y, 2))) <= crl.radius)
             && (j % 8 == 0) && (i % 8 == 0)) ?
            put_pixel(i, j, color, frambuffer) : ++verif;
}

int verif_circle(int i, int j, int x, int y)
{
    int res = (pow((i - x), 2) + pow((j - y), 2));
    if (res < 0)
        res = -res;
    return sqrt(res);
}

void draw_empty_circle(sfColor color, sfUint8 *frambuffer, circle crl)
{
    int verif = 0;
    for (int i = crl.x - crl.radius; i <= crl.x + crl.radius + 1; ++i)
        for (int j = crl.y - crl.radius; j <= crl.y + crl.radius + 1; ++j) {
            ((verif_circle(i, j, crl.x, crl.y) == crl.radius) ||
             (verif_circle(i, j, crl.x, crl.y) == crl.radius - 1) ||
             (verif_circle(i, j, crl.x, crl.y) == crl.radius + 1)) ?
            put_pixel(i, j, color, frambuffer) : ++verif;
        }
}
