/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** interface.c
*/

#include "../includes/world.h"

void init_welcome(window *wndw, options *sprt)
{
     sfVector2f prems = {0, 0};
     sfIntRect first = {0, 0, 1920, 1080};
     sprt->spwelcome = sfSprite_create();
     sfSprite_setTexture(sprt->spwelcome, sprt->welcome, sfTrue);
     sfSprite_setPosition(sprt->spwelcome, prems);
}

void init_fond(window *wndw, options *sprt)
{
     sfVector2f prems = {40, 65 - 915};
     sfIntRect first = {0, 0, 400, 915};
     sprt->spfond = sfSprite_create();
     sfSprite_setTexture(sprt->spfond, sprt->fond, sfTrue);
     sfSprite_setPosition(sprt->spfond, prems);
}

void init_barre(window *wndw, options *sprt)
{
     sfVector2f prems = {0, 0};
     sfIntRect first = {0, 0, 1920, 65};
     sprt->spbarre = sfSprite_create();
     sfSprite_setTexture(sprt->spbarre, sprt->barre, sfTrue);
     sfSprite_setPosition(sprt->spbarre, prems);
}

void init_menu(window *wndw, options *sprt)
{
     sfVector2f prems = {660, 340};
     sfIntRect first = {0, 0, 600, 400};
     sprt->spmenu = sfSprite_create();
     sfSprite_setTexture(sprt->spmenu, sprt->menu, sfTrue);
     sfSprite_setPosition(sprt->spmenu, prems);
}

void init_cuts(window *wndw, options *sprt)
{
     sfVector2f prems = {560, 240};
     sfIntRect first = {0, 0, 800, 600};
     sprt->spcuts = sfSprite_create();
     sfSprite_setTexture(sprt->spcuts, sprt->cuts, sfTrue);
     sfSprite_setPosition(sprt->spcuts, prems);
}
