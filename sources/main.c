/*
** EPITECH PROJECT, 2021
** ouais
** File description:
** main.c
*/

#include "../includes/map.h"

int call_main_func(char *str)
{
    window *wndw = malloc(sizeof(window));
    options *sprt = malloc(sizeof(options));
    main_func(wndw, sprt);
}

int main(int ac, char **av)
{
    call_main_func(av[1]);
}
