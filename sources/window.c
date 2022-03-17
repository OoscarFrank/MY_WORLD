/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-mywndw-oscar.frank
** File description:
** window.c
*/

#include "../includes/map.h"

void params_window(window *wndw, options *sprt)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sprt->welcome = sfTexture_createFromFile("ressources/welcome.png", NULL);
    sprt->fond = sfTexture_createFromFile("ressources/base.png", NULL);
    sprt->barre = sfTexture_createFromFile("ressources/barre.png", NULL);
    sprt->menu = sfTexture_createFromFile("ressources/mode_menu.png", NULL);
    sprt->cuts = sfTexture_createFromFile("ressources/shortcuts.png", NULL);
    sprt->txt_l_s = sfTexture_createFromFile("ressources/text_l_s.png", NULL);
    wndw->window = sfRenderWindow_create(mode, "my_world",
    sfResize | sfClose | sfFullscreen, NULL);
}
