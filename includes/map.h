/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** run
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/System/Export.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
    #include <math.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <stddef.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    //#define height 1080
    //#define width 1920
    #define WIDTH 1920
    #define HEIGHT 1080
    #define MAP_X 50
    #define MAP_Y 50

typedef struct {
    float x;
    float y;
    int delta;
    int radius;
} mouse_c;

typedef struct {
    sfVector2f **map;
    int **td_map;
    float al;
    float be;
    int zoom;
    int decal_x;
    int decal_y;
}maps;

typedef struct {
    sfUint8 *framebuffer;
    sfColor color;
    sfSprite *s;
    sfTexture *t;
    int radius;
    int style;
    sfSprite *nw;
} cursor;

typedef struct {
    int x;
    int y;
    int z;
    float tmp_x;
    float tmp_y;
    float tmp_z;
    float back_x;
} tmp_water;


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
    int (*launch)(window *wndw, options *opt, cursor *c, maps *m);
}button;

void reset_map(maps *m);
int quit_button(window *wndw, options *opt, cursor *c, maps *m);
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
void linked_button(options *opt, window *wndw, cursor *c, maps *m);
void is_touched_button(window *wndw, options *opt);
void catch_button(window *wndw, options *opt, sfEvent event, cursor *c, maps *m);
typedef int (*ptr_f)(window *wndw, options *opt, cursor *c, maps *m);
void click_button(window *wndw, options *opt, sfEvent event);
void factory_button(options *opt, ptr_f fc, sfIntRect old, sfVector2f pos);
void init_cursor(cursor *c);
void init_maps(maps *m);
int move_cursor(cursor *c, sfRenderWindow *wnd, maps *m);
sfColor choose_color(int i, int j, maps *m);
void draw_2d_map(sfRenderWindow *wnd, maps *m);
void create_2d_map(maps *m);
void create_line(int i, int j, maps *m, sfRenderWindow *wnd);
void draw_zero(maps *m, sfRenderWindow *wnd);
void draw_five_five(maps *m, sfRenderWindow *wnd);
void draw_one_one_zero(maps *m, sfRenderWindow *wnd);
void launch_event(maps *m, cursor *c, window *wndw, options *sprt);
void my_world(sfRenderWindow *wnd, maps *m, cursor *c);
#endif
