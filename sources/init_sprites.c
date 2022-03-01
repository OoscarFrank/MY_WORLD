/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** init_sprites.c
*/

#include "../includes/world.h"

void init_sprites(window *wndw, options *sprt)
{
    init_welcome(wndw, sprt);
    init_fond(wndw, sprt);
    init_barre(wndw, sprt);
    init_menu(wndw, sprt);
    init_cuts(wndw, sprt);
}
