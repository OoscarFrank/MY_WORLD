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

void write_save(maps *m, window *wndw)
{
    char *tmp = malloc(sizeof(char) * 1000);
    int cp = 0;
    char *base = "Name of the file : ";
    int i = 0;
    sfVector2f place = {WIDTH / 2, HEIGHT / 2};

    for (; base[cp] != '\0'; ++cp)
        tmp[cp] = base[cp];

    for (; i < m->sv.cp; ++i)
        tmp[cp + i] = m->sv.name_file[i];
    tmp[cp + i] = '\0';
    sfText_setString(m->sv.text, tmp);
    sfText_setPosition(m->sv.text, place);
    sfRenderWindow_drawText(wndw->window, m->sv.text, NULL);
    free(tmp);
}

int loop_instruction(window *wndw, options *sprt, redus_map re)
{
    if (sprt->begin == 0 && sprt->params == 1 || sprt->params == 2 ||
    sprt->params == 4 || sprt->params == 5 || sprt->params == 6)
        draw_spfond(wndw, sprt);
    if (sprt->begin == 0) {
        my_world(wndw->window, re.m, re.c);
        my_world(wndw->window, re.m, re.c);
        draw_spfond(wndw, sprt);
        draw_spbarre(wndw, sprt);
    }
    if (sprt->begin == 3)
        draw_spmenu(wndw, sprt);
    if (sprt->begin == 1)
        draw_spwelcome(wndw, sprt);
    if (re.m->sv.is_save)
        write_save(re.m, wndw);
    return 0;
}

void i_time(options *sprt, window *wndw)
{
    sprt->ti.timer_total += sfClock_getElapsedTime
    (sprt->total_clock).microseconds - sprt->ti.timer;
    while (sprt->ti.timer_total > 16000) {
        if (sprt->mv == 1 && sprt->i < 900)
            sprt->i += 10;
        if (sprt->i >= 900 && sprt->mv == 1)
            open_p(wndw, sprt);
        if (sprt->mv == -1 && sprt->i > -5)
            sprt->i -= 10;
        sprt->ti.timer_total -= 16000;
    }
    sprt->ti.timer = sfClock_getElapsedTime(sprt->total_clock).microseconds;
}

int main_func(window *wndw, options *sprt, maps *m, cursor *c)
{
    sprt->i = 0;
    sprt->total_clock = sfClock_create();
    init_all(wndw, sprt, m, c);
    sprt->ti.timer = 0;
    sprt->ti.timer_total = 0;
    sfRenderWindow_setFramerateLimit(wndw->window, 60);
    while (sfRenderWindow_isOpen(wndw->window)) {
        sfRenderWindow_display(wndw->window);
        launch_event(m, c, wndw, sprt);
        if (sprt->params == 5)
            draw_spcuts(wndw, sprt);
        i_time(sprt, wndw);
        loop_instruction(wndw, sprt, (redus_map) {m, c});
        is_touched_button(wndw, sprt, c);
    }
    return 0;
}
