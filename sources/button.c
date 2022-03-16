/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** button gestion
*/

#include "../includes/map.h"

void touch_button(window *wndw, options *opt, int i, sfVector2i pos)
{
    sfVector2f yes = sfSprite_getPosition(opt->ar_btn[i].sprt);
    sfIntRect tmp = {yes.x, yes.y, opt->ar_btn[i].place.width,
    opt->ar_btn[i].place.height};
    sfIntRect new = {opt->ar_btn[i].place.left, opt->ar_btn[i].place.height,
    opt->ar_btn[i].place.width, opt->ar_btn[i].place.height};
    if (sfIntRect_contains(&tmp, pos.x, pos.y) && opt->ar_btn[i].event != 3) {
        sfSprite_setTextureRect(opt->ar_btn[i].sprt, new);
        opt->ar_btn[i].event = 0;
        } else if (opt->ar_btn[i].event != 3) {
        sfSprite_setTextureRect(opt->ar_btn[i].sprt, opt->ar_btn[i].place);
    }
    if (opt->ar_btn[i].screen == opt->begin && opt->ar_btn[i].params)
        sfRenderWindow_drawSprite(wndw->window, opt->ar_btn[i].sprt, NULL);
}

void is_touched_button(window *wndw, options *opt, cursor *c)
{
    sfVector2i pos = sfMouse_getPosition(NULL);
    for (int i = 0; i < opt->len_button; ++i)
        touch_button(wndw, opt, i, pos);
}

void factory_button(options *opt, ptr_f fc, sfIntRect old, sfVector2f pos)
{
    button btn;
    btn.sprt = sfSprite_create();
    btn.place = old;
    btn.pos = pos;
    btn.launch = fc;
    btn.event = 0;
    sfSprite_setTexture(btn.sprt, opt->t, sfTrue);
    sfSprite_setTextureRect(btn.sprt, old);
    sfSprite_setPosition(btn.sprt, pos);
    opt->ar_btn[opt->len_button] = btn;
    ++opt->len_button;
}

void move_rect_pressed(options *opt, int i)
{
    sfIntRect new = {opt->ar_btn[i].place.left,
    opt->ar_btn[i].place.height * 2,
    opt->ar_btn[i].place.width, opt->ar_btn[i].place.height};
    sfSprite_setTextureRect(opt->ar_btn[i].sprt, new);
    opt->ar_btn[i].event = 3;
}
