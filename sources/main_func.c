/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main_func.c
*/

#include "../includes/map.h"

int init_all(window *wndw, options *sprt, maps *m, cursor *c)
{
    sprt->begin = 1;
    sprt->params = 0;
    init_cursor(c);
    init_maps(m);
    params_window(wndw, sprt);
    init_sprites(wndw, sprt);
    linked_button(sprt, wndw, c, m);
    return 0;
}

int loop_instruction(window *wndw, options *sprt, maps *m, cursor *c, int i)
{
    if (sprt->begin == 0 && sprt->params == 1 || sprt->params == 2 ||
    sprt->params == 4 || sprt->params == 5 || sprt->params == 6)
        draw_spfond(wndw, sprt, i);
    if (sprt->begin == 0) {
        my_world(wndw->window, m, c);
        my_world(wndw->window, m, c);
        draw_spfond(wndw, sprt, i);
        draw_spbarre(wndw, sprt);
    }
    if (sprt->begin == 3)
        draw_spmenu(wndw, sprt);
    if(sprt->begin == 1)
        draw_spwelcome(wndw, sprt);
    return 0;
}

int main_func(window *wndw, options *sprt, maps *m, cursor *c)
{
    int i = 0;
    int j = 0;
    init_all(wndw, sprt, m, c);
    while (sfRenderWindow_isOpen(wndw->window)) {
        sfRenderWindow_display(wndw->window);
        sfRenderWindow_clear(wndw->window, sfBlack);
        launch_event(m, c, wndw, sprt);
        if (sprt->params == 5)
            draw_spcuts(wndw, sprt);
        if (sprt->mv == 1 && i < 912)
            ++i;
        if (i == 912 && sprt->mv == 1)
            open_p(wndw, sprt);
        if (sprt->mv == -1 && i > - 5)
            --i;
        loop_instruction(wndw, sprt, m, c, i);
        is_touched_button(wndw, sprt, c);
    }
    return 0;
}
