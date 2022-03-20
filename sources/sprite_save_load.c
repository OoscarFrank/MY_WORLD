/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** sprite_save_load.c
*/

#include "../includes/map.h"


void init_txt_l_s(window *wndw, options *sprt)
{
    sfVector2f prems = {660, 440};
    sfIntRect first = {0, 0, 800, 600};
    sprt->sptxt_l_s = sfSprite_create();
    sfSprite_setTexture(sprt->sptxt_l_s, sprt->txt_l_s, sfTrue);
    sfSprite_setPosition(sprt->sptxt_l_s, prems);
}

void draw_sp_txt_ls(window *wndw, options *sprt)
{
    sfRenderWindow_drawSprite(wndw->window, sprt->sptxt_l_s, NULL);
}
