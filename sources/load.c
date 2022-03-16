/*
** EPITECH PROJECT, 2022
** world
** File description:
** load
*/

#include "../includes/map.h"

void len_y_x(char *str, maps *m)
{
    m->map_x = 0;
    m->map_y = 0;
    for (int i = 0; str[i] != '\n'; ++i)
        if (str[i] == ',')
            ++m->map_x;
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '\n')
            ++m->map_y;
}

int next_number(int **nw_map, pos p, char *tmp, int cp)
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
    nw_map[p.y][p.x] = nxt * multi;
    for (; tmp[cp] == ',' || tmp[cp] == '\n'; ++cp);
    return cp;
}

int chg_map(maps *m)
{
    int fd = open(m->sv.name_file, O_RDONLY);
    int **nw_map;
    char *tmp = malloc(sizeof(char) * 10000000);
    int len = 0;
    int cp = 0;
    if (fd == - 1)
        return 1;
    len = read(fd, tmp, 10000000);
    tmp[len] = '\0';
    len_y_x(tmp, m);
    nw_map = malloc(sizeof(int *) * (2 * (m->map_y + 1)));
    for (int i = 0; i < m->map_y; ++i) {
        nw_map[i] = malloc(sizeof(int) * (2 * (m->map_x + 1)));
        for (int j = 0; j < m->map_x; ++j)
            cp = next_number(nw_map, (pos){j, i}, tmp, cp);
    }
    m->td_map = nw_map;
    return 0;
}

void load_map(maps *m, sfEvent event, options *sprt)
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
        event.key.code == sfKeyBackspace && m->sv.cp > 0 ? --m->sv.cp : 0;
    }
    if (event.type == sfEvtKeyReleased)
        if (event.key.code == sfKeyLControl || event.key.code == sfKeyRControl)
            sprt->ctrl_pressed = 0;
}

void start_load(maps *m)
{
    m->sv.is_save = 2;
    m->sv.cp = 0;
}
