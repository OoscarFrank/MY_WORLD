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
    #define WIDTH 1920
    #define HEIGHT 1080

typedef struct {
    float x;
    float y;
    int delta;
    int radius;
}mouse_c;

typedef struct {
    char *name_file;
    int cp;
    int is_save;
    int old_ch;
}save_map;

typedef struct {
    sfVector2f **map;
    int **td_map;
    sfVector2f **water_map;
    float al;
    float be;
    int zoom;
    int decal_x;
    int decal_y;
    int map_x;
    int map_y;
    save_map sv;
}maps;

typedef struct {
    sfUint8 *framebuffer;
    sfColor color;
    sfSprite *s;
    sfTexture *t;
    int radius;
    int style;
    sfSprite *nw;
    int ctrl_pressed;
}cursor;

typedef struct {
    int x;
    int y;
    int z;
    float tmp_x;
    float tmp_y;
    float tmp_z;
    float back_x;
}tmp_water;


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
    int ctrl_pressed;
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

typedef struct {
    int x;
    int y;
    int radius;
}circle;

typedef struct {
    float angle;
    float ang_h;
    float angle_b;
    float angle_a;
    float tmp_x;
    float tmp_y;
    float tmp_z;
    float back_x;
}angle_bs;

typedef struct {
    maps *m;
    cursor *c;
}redus_map;

typedef struct {
    int x;
    int y;
}pos;

void button_mouse(sfRenderWindow *window, maps *m, cursor *c);
void start_save(maps *m);
void save(maps *m, sfEvent event);
void key_q(maps *m);
void key_d(maps *m);
void reset_map(maps *m);
int quit_button(window *wndw, options *opt, cursor *c, maps *m);
int main_func(window *wndw, options *sprt, maps *m, cursor *c);
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
void is_touched_button(window *wndw, options *opt, cursor *c);
void catch_button(window *wndw, options *opt, sfEvent event, redus_map r_map);
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
int open_p(window *wndw, options *opt);
void mouse_event(sfEvent event, cursor *c, maps *m, options *sprt);
int quit_button(window *wndw, options *opt, cursor *c, maps *m);
int continue_button(window *wndw, options *opt, cursor *c, maps *m);
int open_menu(window *wndw, options *opt, cursor *c, maps *m);
int resume_game(window *wndw, options *opt, cursor *c, maps *m);
int go_home(window *wndw, options *opt, cursor *c, maps *m);

int go_up(window *wndw, options *opt, cursor *c, maps *m);
int turn_left(window *wndw, options *opt, cursor *c, maps *m);
int turn_right(window *wndw, options *opt, cursor *c, maps *m);
int turn_high(window *wndw, options *opt, cursor *c, maps *m);
int turn_low(window *wndw, options *opt, cursor *c, maps *m);

int zoom_out(window *wndw, options *opt, cursor *c, maps *m);
int reset_button(window *wndw, options *opt, cursor *c, maps *m);
int go_left(window *wndw, options *opt, cursor *c, maps *m);
int go_right(window *wndw, options *opt, cursor *c, maps *m);
int go_down(window *wndw, options *opt, cursor *c, maps *m);

int close_params(window *wndw, options *opt, cursor *c, maps *m);
int open_view(window *wndw, options *opt, cursor *c, maps *m);
int close_view(window *wndw, options *opt, cursor *c, maps *m);
int open_turn(window *wndw, options *opt, cursor *c, maps *m);
int close_turn(window *wndw, options *opt, cursor *c, maps *m);

int open_p(window *wndw, options *opt);
int open_params(window *wndw, options *opt, cursor *c, maps *m);
int open_zoom(window *wndw, options *opt, cursor *c, maps *m);
int close_zoom(window *wndw, options *opt, cursor *c, maps *m);
int open_shortcuts(window *wndw, options *opt, cursor *c, maps *m);
int close_shortcuts(window *wndw, options *opt, cursor *c, maps *m);
int zoom_in(window *wndw, options *opt, cursor *c, maps *m);
void linked_button(options *opt, window *wndw, cursor *c, maps *m);
void second_part_button(window *wndw, options *opt, cursor *c, maps *m);
void third_part_button(window *wndw, options *opt, cursor *c, maps *m);
void fourth_part_button(window *wndw, options *opt, cursor *c, maps *m);
void fifth_part_button(window *wndw, options *opt, cursor *c, maps *m);
void sixth_part_button(window *wndw, options *opt, cursor *c, maps *m);
void seven_part_button(window *wndw, options *opt, cursor *c, maps *m);
void eight_part_button(window *wndw, options *opt, cursor *c, maps *m);
sfColor biggest(int x, int y, maps *m);
void click_button(window *wndw, options *opt, sfEvent event);
void draw_water(int i, int j, maps *m, sfRenderWindow *wnd);
void move_rect_pressed(options *opt, int i);
void put_pixel(int x, int y, sfColor color, sfUint8 *framebuffer);
void draw_circle(sfColor color, sfUint8 *frambuffer, circle crl);
void put_pixel(int x, int y, sfColor color, sfUint8 *framebuffer);
void draw_empty_circle(sfColor color, sfUint8 *frambuffer, circle crl);
#endif
