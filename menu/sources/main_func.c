/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main_func.c
*/

#include "../includes/world.h"

int main_func(window *wndw, options *sprt)
{
    int i = 0;
    int j = 0;
    sprt->begin = 1;
    sprt->params = 0;
    params_window(wndw, sprt);
    init_sprites(wndw, sprt);
    linked_button(sprt, wndw);
    while (sfRenderWindow_isOpen(wndw->window)) {
        sfRenderWindow_display(wndw->window);
        sfRenderWindow_clear(wndw->window, sfBlack);
        event_window(wndw, sprt);
        if (sprt->params == 5)
            draw_spcuts(wndw, sprt);
        if (sprt->mv == 1 && i < 912)
            ++i;
        if (i == 912 && sprt->mv == 1)
            open_p(wndw, sprt);
        if (sprt->mv == -1 && i > - 5)
            --i;
        if (sprt->begin == 0 && sprt->params == 1 || sprt->params == 2 || sprt->params == 4 || sprt->params == 5 || sprt->params == 6)
            draw_spfond(wndw, sprt, i);
        if (sprt->begin == 0)
            draw_spbarre(wndw, sprt);
        if (sprt->begin == 3)
            draw_spmenu(wndw, sprt);
        if(sprt->begin == 1)
            draw_spwelcome(wndw, sprt);
        is_touched_button(wndw, sprt);
    }
}
