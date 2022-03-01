/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** first
*/

#include "../includes/map.h"
#include "../includes/world.h"

void mouse_event(sfEvent event, sfRenderWindow *window, maps *m, cursor *c)
{
    if (event.type == sfEvtMouseWheelScrolled) {
        if (event.mouseWheelScroll.delta == 1)
            ++c->radius;
        else
            --c->radius;
    }
}

void reset_map(maps *m)
{
    for (int y = 0; y < MAP_Y; ++y)
        for (int x = 0; x < MAP_X; ++x)
            m->td_map[y][x] = 0;
}

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

void move_event(sfEvent event, window *wndw, maps *m, options *sprt)
{
    if (event.key.code == sfKeyZ)
        ++m->be;
    if (event.key.code == sfKeyS)
        --m->be;
    if (event.key.code == sfKeyD)
        key_d(m);
    if (event.key.code == sfKeyA)
        ++m->zoom;
    if (event.key.code == sfKeyE)
        --m->zoom;
    if (event.key.code == sfKeyQ)
        key_q(m);
    if (event.key.code == sfKeyLeft)
        m->decal_x -= 20;
    if (event.key.code == sfKeyRight)
        m->decal_x += 20;
    if (event.key.code == sfKeyDown)
        m->decal_y += 20;
    if (event.key.code == sfKeyUp)
            m->decal_y -= 20;
    if (event.key.code == sfKeySpace)
        reset_map(m);
    if (event.key.code == sfKeyL)
        sprt->begin = 0;
    if (sfKeyR == event.key.code && sprt->begin == 3)
        sprt->begin = 0;
    if (sfKeyM == event.key.code && sprt->begin == 0)
            sprt->begin = 3;
}

void incidence(maps *m, int y, int x, mouse_c p)
{
    int tmp = 0;
    if (y + 1 < MAP_Y && x + 1 < MAP_X && x > 0 && y > 0) {
        tmp = m->td_map[y][x] - 8;
        if (m->td_map[y + 1][x] < tmp) {
            m->td_map[y + 1][x] += p.delta;
            incidence(m, y + 1, x, p);
        }
        if (m->td_map[y][x + 1] < tmp) {
            m->td_map[y][x + 1] += p.delta;
            incidence(m, y, x + 1, p);
        }
        if (m->td_map[y][x - 1] < tmp) {
            m->td_map[y][x - 1] += p.delta;
            incidence(m, y, x - 1, p);
        }
        if (m->td_map[y - 1][x] < tmp) {
            m->td_map[y - 1][x] += p.delta;
            incidence(m, y - 1, x, p);
        }
    }
}

void check_mouse_pos(maps *m, int y, int x, mouse_c p)
{
    if ((m->map[y][x].x <= (p.x + p.radius)) && (m->map[y][x + 1].x >= (p.x - p.radius)) &&
    ((m->map[y][x].y <= (p.y + p.radius)) && (m->map[y + 1][x].y >= (p.y - p.radius)))) {
        m->td_map[y][x] += p.delta;
        incidence(m, y, x, p);
    }
}

void go_in_array(maps *m, mouse_c p)
{
    for (int y = 0; y < MAP_Y - 2; ++y)
        for (int x = 0; x < MAP_X - 2; ++x)
            check_mouse_pos(m, y, x, p);
}

void button_mouse(sfRenderWindow *window, maps *m, cursor *c)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        go_in_array(m, (mouse_c) {pos.x, pos.y, 1, c->radius / 2});
    if (sfMouse_isButtonPressed(sfMouseRight))
        go_in_array(m, (mouse_c) {pos.x, pos.y, - 1, c->radius / 2});
    if (sfMouse_isButtonPressed(sfMouseMiddle))
        c->style = c->style ? 0 : 1;
}
    
void launch_event(maps *m, cursor *c, window *wndw, options *sprt)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wndw->window, &event)) {
    if (event.type == sfEvtMouseButtonReleased)
        catch_button(wndw, sprt, event);
    if (event.type == sfEvtMouseButtonPressed)
        click_button(wndw, sprt, event);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(wndw->window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(wndw->window);
        move_event(event, wndw, m, sprt);
    }
    mouse_event(event, wndw->window, m, c);
    button_mouse(wndw->window, m, c);
    }
}

int diff_color(maps *m, int i, int j, int max)
{
    int tmp = (3 * (j % 2)) + (m->td_map[i][j] / 2) + (3 * (i % 2));
    return tmp <= max ? tmp : max;
}

sfColor choose_color(int i, int j, maps *m)
{
    if (m->td_map[i][j] > 5 && m->td_map[i][j] < 50)
        return sfColor_fromRGB(105 + diff_color(m, i, j, 200), 105 + diff_color(m, i, j, 200), 105 + diff_color(m, i, j, 200));
    if (m->td_map[i][j] >= 50 || m->td_map[i][j] < 0)
        return sfColor_fromRGB(200 + diff_color(m, i, j, 54), 200 + diff_color(m, i, j, 54), 200 + diff_color(m, i, j, 54));
    return sfColor_fromRGB(91, 139 + diff_color(m, i, j, 255), 50);
}

void my_world(sfRenderWindow *wnd, maps *m, cursor *c)
{
    sfRenderWindow_clear(wnd, sfBlack);
    draw_2d_map(wnd, m);
    move_cursor(c, wnd, m);
}

/*
int main(void)
{
    maps *m = malloc(sizeof(maps) + 1);
    cursor *c = malloc(sizeof(cursor) + 1);
    sfEvent event;
    init_cursor(c);
    init_maps(m);
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *wnd = sfRenderWindow_create(mode, "w", sfFullscreen, NULL);
    sfRenderWindow_setMouseCursorVisible(wnd, sfFalse);
    while (sfRenderWindow_isOpen(wnd)) {
        while (sfRenderWindow_pollEvent(wnd, &event))
            launch_event(event, wnd, m, c);
        my_world(wnd, m, c);
        sfRenderWindow_display(wnd);
    }
    return 0;
}

*/