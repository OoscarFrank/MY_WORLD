/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** save map
*/

#include "../includes/map.h"

int put_int_rec(int nb, char *content_file, int *cp)
{
    int last_digit;
    if (nb == 0)
        return 0;
    last_digit = nb % 10;
    put_int_rec(nb / 10, content_file, cp);
    content_file[*cp] = last_digit + 48;
    ++*cp;
    return 1;
}

void put_int(maps *m, pos p, int *cp, char *content_file)
{
    int tmp = m->td_map[p.y][p.x];

    if (tmp == 0) {
        content_file[*cp] = '0';
        ++*cp;
    }
    if (tmp < 0) {
        tmp = -tmp;
        content_file[*cp] = '-';
        ++*cp;
    }
    put_int_rec(tmp, content_file, cp);
    content_file[*cp] = ',';
    ++*cp;
}

void create_content_map(maps *m, char *name_file)
{
    char *content_file = malloc(sizeof(char) * (m->map_y * m->map_x) * 100);
    int *cp = malloc(sizeof(int) * 1);
    FILE *file = fopen(name_file, "w+");

    *cp = 0;
    for (int y = 0; y < m->map_y; ++y) {
        for (int x = 0; x < m->map_x; ++x)
            put_int(m, (pos){x, y}, cp, content_file);
        content_file[*cp] = '\n';
        ++*cp;
    }
    content_file[*cp] = '\0';
    fwrite(content_file, *cp, 1, file);
    fclose(file);
}

void save(maps *m, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEnter) {
            m->sv.name_file[m->sv.cp] = '\0';
            create_content_map(m, m->sv.name_file);
            m->sv.is_save = 0;
        }
        if (event.key.code >= 0 && event.key.code < 26) {
            m->sv.name_file[m->sv.cp] = event.key.code + 97;
            ++m->sv.cp;
        }
        event.key.code == sfKeyReturn && m->sv.cp > 0 ? --m->sv.cp : 0;
    }
}

void start_save(maps *m)
{
    m->sv.is_save = 1;
    m->sv.cp = 0;
}
