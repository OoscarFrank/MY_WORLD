/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-mywndw-oscar.frank
** File description:
** window.c
*/

#include "../includes/world.h"

void params_window(window *wndw, options *sprt)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sprt->welcome = sfTexture_createFromFile("ressources/welcome.png", NULL);
    sprt->fond = sfTexture_createFromFile("ressources/base.png", NULL);
    sprt->barre = sfTexture_createFromFile("ressources/barre.png", NULL);
    sprt->menu = sfTexture_createFromFile("ressources/mode_menu.png", NULL);
    sprt->cuts = sfTexture_createFromFile("ressources/shortcuts.png", NULL);
    wndw->window = sfRenderWindow_create(mode, "my_world", sfResize | sfClose |
    sfFullscreen, NULL);
}

int event_window(window *wndw, options *sprt)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wndw->window, &event)) {
        if (event.type == sfEvtKeyPressed && sfKeyEscape == event.key.code)
            sfRenderWindow_close(wndw->window);
        if (event.type == sfEvtKeyPressed && sfKeyL == event.key.code)
            sprt->begin = 0;
        if (event.type == sfEvtMouseButtonReleased)
            catch_button(wndw, sprt, event);
        if (event.type == sfEvtMouseButtonPressed)
            click_button(wndw, sprt, event);
        if (event.type == sfEvtKeyPressed && sfKeyR == event.key.code &&
        sprt->begin == 3)
            sprt->begin = 0;
        if (event.type == sfEvtKeyPressed && sfKeyM == event.key.code &&
        sprt->begin == 0)
            sprt->begin = 3;
    }
    return 0;
}
