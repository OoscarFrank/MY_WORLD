/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** run
*/

#ifndef WORLD_H_
    #define WORLD_H_

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
    #define height 1080
    #define width 1920

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

void init_cursor(cursor *c);
void init_maps(maps *m);
//void move_cursor(cursor *c, sfRenderWindow *wnd);
sfColor choose_color(int i, int j, maps *m);
void draw_2d_map(sfRenderWindow *wnd, maps *m);
void create_2d_map(maps *m);
void create_line(int i, int j, maps *m, sfRenderWindow *wnd);
void draw_zero(maps *m, sfRenderWindow *wnd);
void draw_five_five(maps *m, sfRenderWindow *wnd);
void draw_one_one_zero(maps *m, sfRenderWindow *wnd);
#endif
