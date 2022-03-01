/*
** EPITECH PROJECT, 2022
** ouais
** File description:
** world
*/

#ifndef WORLD_H_
    #define WORLD_H_

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <stddef.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #define WIDTH 1920
    #define HEIGHT 1080
    #include <stdio.h>
    #define nb_buttons 2

typedef struct {
    sfRenderWindow *window;
    struct sfTexture *texture;
    struct sfSprite *sprite;
}window;

typedef struct {
    int mv;
    int params;
    int begin;
    int len_button;
    sfTexture *welcome;
    sfSprite *spwelcome;
    sfTexture *fond;
    sfSprite *spfond;
    sfTexture *barre;
    sfSprite *spbarre;
    sfTexture *menu;
    sfSprite *spmenu;
    sfTexture *cuts;
    sfSprite *spcuts;
    sfTexture *t;
    struct button *ar_btn;
}options;

typedef enum button_name {
    ESCAPE_PROG,
    CONTINUE,
    ESCAPE_PRCP,
    OPEN_MENU,
    ESCAPE_MENU,
    RESUME_MENU,
    HOME_MENU,
    OPEN_PARAMS,
    SAVE_FILE,
    LOG_OUT,
    CLOSE_PARAMS,
    OPEN_CHG_VIEW,
    FLECHE_GAUCHE,
    FLECHE_BAS,
    FLECHE_DROITE,
    FLECHE_HAUT,
    CLOSE_VIEW,
    OPEN_TURN,
    TURN_MAP_L,
    TURN_MAP_B,
    TURN_MAP_R,
    TURN_MAP_H,
    CLOSE_TURN,
    OPEN_ZOOM,
    ZOOM,
    DZOOM,
    CLOSE_ZOOM,
    RESET_MAP,
    SHORTCUTS,
    CLOSE_SHORTCUTS,
}buttton_name;

typedef struct button{
    int params;
    int screen;
    int event;
    sfSprite *sprt;
    sfIntRect place;
    sfVector2f pos;
    int (*launch)(window *wndw, options *opt);
}button;

int main_func(window *wndw, options *sprt);

void params_window(window *wndw, options *sprt);
int event_window(window *wndw, options *sprt);

void init_fond(window *wndw, options *otln);
void draw_spfond(window *wndw, options *otln, int i);
void init_off(window *wndw, options *sprt);
void init_welcome(window *wndw, options *sprt);
void draw_spwelcome(window *wndw, options *sprt);
void init_off_m_o(window *wndw, options *sprt);
void init_barre(window *wndw, options *sprt);
void draw_spbarre(window *wndw, options *sprt);
void init_menu(window *wndw, options *sprt);
void draw_spmenu(window *wndw, options *sprt);
void init_cuts(window *wndw, options *sprt);
void draw_spcuts(window *wndw, options *sprt);

void init_sprites(window *wndw, options *sprt);

void linked_button(options *opt, window *wndw);
void is_touched_button(window *wndw, options *opt);
void catch_button(window *wndw, options *opt, sfEvent event);
typedef int (*ptr_f)(window *wndw, options *opt);
void click_button(window *wndw, options *opt, sfEvent event);
void factory_button(options *opt, ptr_f fc, sfIntRect old, sfVector2f pos);
int go_home(window *wndw, options *opt);
int open_p(window *wndw, options *opt);

#endif
