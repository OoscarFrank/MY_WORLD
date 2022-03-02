/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-robin.denni
** File description:
** detect_button.c
*/

#include "../includes/map.h"

void catch_button(window *wndw, options *opt, sfEvent event, cursor *c, maps *m)
{
    for (int i = 0; i < opt->len_button; ++i) {
        if (opt->ar_btn[i].params == 1 && ((event.mouseButton.x >= opt->ar_btn[i].pos.x) &&
        (event.mouseButton.x <= (opt->ar_btn[i].pos.x +
        opt->ar_btn[i].place.width))) && ((event.mouseButton.y >=
        opt->ar_btn[i].pos.y) && (event.mouseButton.y <=
        (opt->ar_btn[i].pos.y + opt->ar_btn[i].place.height) &&
        opt->ar_btn[i].screen == opt->begin)))
            (*(opt->ar_btn[i].launch))(wndw, opt, c, m);
        opt->ar_btn[i].event = 0;
    }
}

void click_button(window *wndw, options *opt, sfEvent event)
{
        for (int i = 0; i < opt->len_button; ++i) {
        if (((event.mouseButton.x >= opt->ar_btn[i].pos.x) &&
        (event.mouseButton.x <= (opt->ar_btn[i].pos.x +
        opt->ar_btn[i].place.width))) && ((event.mouseButton.y >=
        opt->ar_btn[i].pos.y) && (event.mouseButton.y <=
        (opt->ar_btn[i].pos.y + opt->ar_btn[i].place.height) &&
        opt->ar_btn[i].screen == opt->begin)))
            move_rect_pressed(opt, i);
    }
}
