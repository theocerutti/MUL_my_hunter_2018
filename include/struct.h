/*
** EPITECH PROJECT, 2018
** Header of struct
** File description:
** Header of struct
*/

typedef struct sprite {
    int width;
    int height;
    int offset[2];
    sfVector2f v;
    sfVector2f pos;
    sfVector2f scale_size;
    sfTexture *t;
    sfSprite *s;
    sfIntRect rect;
} sprite;

typedef struct node
{
    sprite f;
    struct node *next;
} node;
typedef node *l_list;

typedef struct txt_st {
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
    int size;
    int score;
} txt_st;

typedef struct life_st {
    sfTexture *tab_life[4];
    sfSprite *s;
    sfVector2f pos;
    sfVector2f scale;
    int index;
} life_st;

typedef struct clock_st {
    sfClock *clock;
    sfTime time;
    float s;
} clock_st;

typedef struct data_st {
    l_list lf;
    sprite tab_f[4];
    l_list l_bg;
    life_st life;
    sfSprite *heart_s;
    sprite ship;
    sprite cursor;
    clock_st *tab_clock;
    txt_st txt_score;
    txt_st txt_loose[2];
    txt_st txt_high_score;
    sfSound *sound_hit;
    sfSoundBuffer *buffer_sound;
    sfMusic *music;
} data_st;