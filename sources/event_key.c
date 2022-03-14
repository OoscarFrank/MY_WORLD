/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** event key
*/

#include "../includes/map.h"

void key_q(maps *m)
{
    if (m->al >= 1)
        m->al -= 2;
}

void key_d(maps *m)
{
    if ((m->al < 145) && (m->al >= 0))
        m->al += 2;
}

void len_y_x(char *str, int *params)
{
    params[0] = 0;
    params[1] = 0;
    for (int i = 0; str[i] != '\n'; ++i)
        if (str[i] == ',')
            ++params[1];
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '\n')
            ++params[0];
}

int next_number(int **nw_map, int i, int j, char *tmp, int cp)
{
    int nxt = 0;
    int multi = 1;
    if (tmp[cp] == '-') {
        multi = -1;
        ++cp;
    }
    while (tmp[cp] != ',' && tmp[cp] != '\n') {
        nxt *= 10;
        nxt += tmp[cp] - 48;
        ++cp;
    }
    nw_map[i][j] = nxt * multi;
    for (; tmp[cp] == ',' || tmp[cp] == '\n'; ++cp);
    return cp;
}

int chg_map(maps *m)
{
    int fd = open(m->sv.name_file, O_RDONLY);
    int **nw_map;
    char *tmp = malloc(sizeof(char) * 10000000);
    int len = 0;
    int *params = malloc(sizeof(int) * 2);
    int cp = 0;
    if (fd == - 1)
        return 1;
    len = read(fd, tmp, 10000000);
    tmp[len] = '\0';
    len_y_x(tmp, params);
    nw_map = malloc(sizeof(int *) * (2 * (params[0] + 1)));
    for (int i = 0; i < params[0]; ++i) {
        nw_map[i] = malloc(sizeof(int) * (2 * (params[1] + 1)));
        for (int j = 0; j < params[1]; ++j)
            cp = next_number(nw_map, i, j, tmp, cp);
    }
    m->map_x = params[1];
    m->map_y = params[0];
    m->td_map = nw_map;
    return 0;
}

void load_map(maps *m, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEnter) {
            m->sv.name_file[m->sv.cp] = '\0';
            chg_map(m);
            m->sv.is_save = 0;
        }
        if (event.key.code >= 0 && event.key.code < 26) {
            m->sv.name_file[m->sv.cp] = event.key.code + 97;
            ++m->sv.cp;
        }
        event.key.code == sfKeyReturn && m->sv.cp > 0 ? --m->sv.cp : 0;
    }
}

void start_load(maps *m)
{
    m->sv.is_save = 2;
    m->sv.cp = 0;
}


void move_event(sfEvent event, window *wndw, maps *m, options *sprt)
{
    int tmp = 0;
    (event.key.code == sfKeyEscape) ? sfRenderWindow_close(wndw->window) : ++tmp;
    (event.key.code == sfKeyZ) ? ++m->be : ++tmp;
    (event.key.code == sfKeyS) ? (sprt->ctrl_pressed) ? start_save(m) : --m->be : ++tmp;
    (event.key.code == sfKeyD) ? key_d(m) : ++tmp;
    (event.key.code == sfKeyA) ? ++m->zoom : ++tmp;
    (event.key.code == sfKeyE) ? --m->zoom : ++tmp;
    (event.key.code == sfKeyQ) ? (sprt->ctrl_pressed) ? start_load(m) : key_q(m) : ++tmp;
    (event.key.code == sfKeyLeft) ? m->decal_x -= 20 : ++tmp;
    (event.key.code == sfKeyRight) ? m->decal_x += 20 : ++tmp;
    (event.key.code == sfKeyDown) ? m->decal_y += 20 : ++tmp;
    (event.key.code == sfKeyUp) ? m->decal_y -= 20 : ++tmp;
    (event.key.code == sfKeySpace) ? reset_map(m) : ++tmp;
    (event.key.code == sfKeyL) ? sprt->begin = 0 : ++tmp;
    (sfKeyR == event.key.code && sprt->begin == 3) ? sprt->begin = 0 : ++tmp;
    (sfKeyM == event.key.code && sprt->begin == 0) ? sprt->begin = 3 : ++tmp;
    (event.key.code == sfKeyT) ? ++m->map_y : ++tmp;
    (event.key.code == sfKeyG) ? --m->map_y : ++tmp;
    (event.key.code == sfKeyF) ? ++m->map_x : ++tmp;
    (event.key.code == sfKeyH) ? --m->map_x : ++tmp;
}

void normal_event(redus_map re, window *wndw, options *sprt, sfEvent event)
{
    if (event.type == sfEvtMouseButtonReleased)
        catch_button(wndw, sprt, event, re);
    if (event.type == sfEvtMouseButtonPressed)
        click_button(wndw, sprt, event);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wndw->window);
    if (event.type == sfEvtKeyPressed) {
        move_event(event, wndw, re.m, sprt);
        if (event.key.code == sfKeyLControl || event.key.code == sfKeyRControl)
            sprt->ctrl_pressed = 1;
    }
    if (event.type == sfEvtKeyReleased)
        if (event.key.code == sfKeyLControl || event.key.code == sfKeyRControl)
            sprt->ctrl_pressed = 0;
    mouse_event(event, re.c, re.m, sprt);
    button_mouse(wndw->window, re.m, re.c);
}

void launch_event(maps *m, cursor *c, window *wndw, options *sprt)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(wndw->window, &event))
        m->sv.is_save ? (m->sv.is_save == 1) ? save(m, event) : load_map(m, event) :
        normal_event((redus_map) {m, c}, wndw, sprt, event);
}
