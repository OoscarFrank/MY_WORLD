/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** draw_sprites.c
*/

#include "../includes/map.h"

void draw_spwelcome(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->spwelcome, NULL);
}

void draw_spfond(window *wndw, options *sprt)
{
    sfVector2f prems = {40, 65 - 915 + sprt->i};
    sfSprite_setPosition(sprt->spfond, prems);
    sfRenderWindow_drawSprite(wndw->window, sprt->spfond, NULL);
}

void draw_spbarre(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->spbarre, NULL);
}

void draw_spmenu(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->spmenu, NULL);
}

void draw_spcuts(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->spcuts, NULL);
}
