/*
** EPITECH PROJECT, 2018
** Init data
** File description:
** Init data
*/

#include "../include/my_hunter.h"

void init_list_background_data(data_st *data)
{
    sfVector2f s = {0.9, 0.9};
    sprite ship = {2814, 131, {201, 201}, {10, 10}, {50, 225}, s, 0, 0, 0};
    sprite bg_n = {3200, 600, {3, 1600}, {0, 0}, {0, 0}, {1, 1}, 0, 0, 0};
    sprite bg_m = {3200, 600, {2, 1600}, {0, 0}, {0, 0}, {1, 1}, 0, 0, 0};
    sprite bg_f = {3200, 600, {1, 1600}, {0, 0}, {0, 0}, {1, 1}, 0, 0, 0};
    l_list list_bg = NULL;

    init_sprite(&bg_n, "lib/images/background/near.png");
    init_sprite(&bg_m, "lib/images/background/medium.png");
    init_sprite(&bg_f, "lib/images/background/far.png");
    init_sprite(&ship, "lib/images/submarine.png");
    list_bg = push(list_bg, bg_f);
    list_bg = push(list_bg, bg_m);
    list_bg = push(list_bg, bg_n);
    data->l_bg = list_bg;
    data->ship = ship;
}

void init_txt_data(data_st *data)
{
    int sco = get_highest_score("score.txt");
    char str[50] = "Highest score: ";
    txt_st txt_score = {NULL, NULL, {780, 30}, sfBlack, 40, 0};
    txt_st high = {NULL, NULL, {1280, 30}, sfBlack, 20, 0};
    txt_st txt_loose1 = {NULL, NULL, {480, 140}, sfBlack, 160, 0};
    txt_st txt_loose2 = {NULL, NULL, {445, 310}, sfBlack, 80, 0};
    txt_st txt_loose[2];

    init_txt(&high, "lib/font/Fipps.otf", my_strcat(str, my_itoa(sco)));
    init_txt(&txt_loose1, "lib/font/Gourmet.otf", NULL);
    init_txt(&txt_loose2, "lib/font/Gourmet.otf", NULL);
    init_txt(&txt_score, "lib/font/Fipps.otf", "0");
    txt_loose[0] = txt_loose1;
    txt_loose[1] = txt_loose2;
    data->txt_score = txt_score;
    data->txt_loose[0] = txt_loose[0];
    data->txt_loose[1] = txt_loose[1];
    data->txt_high_score = high;
}

void init_music_data(data_st *data)
{
    sfMusic *music = sfMusic_createFromFile("lib/music/level_theme01.ogg");
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile("lib/sound/hit.ogg");
    sfSound *sound_hit = sfSound_create();

    sfMusic_setVolume(music, 50.0);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    sfSound_setBuffer(sound_hit, buffer);
    sfSound_setVolume(sound_hit, 60.0);
    data->sound_hit = sound_hit;
    data->buffer_sound = buffer;
    data->music = music;
}

void init_heart_cursor_data(data_st *data)
{
    sprite curs = {512, 512, {512, 512}, {0, 0}, {0, 0}, {0.1, 0.1}, 0, 0, 0};
    sfTexture *h3 = sfTexture_createFromFile("lib/images/heart/life_3.png", 0);
    sfTexture *h2 = sfTexture_createFromFile("lib/images/heart/life_2.png", 0);
    sfTexture *h1 = sfTexture_createFromFile("lib/images/heart/life_1.png", 0);
    sfTexture *h0 = sfTexture_createFromFile("lib/images/heart/life_0.png", 0);
    sfSprite *heart_s = sfSprite_create();
    life_st life = {{h3, h2, h1, h0}, heart_s, {725, 515}, {2.3, 2.3}, 0};

    init_sprite(&curs, "lib/images/cursor.png");
    sfSprite_setPosition(life.s, life.pos);
    sfSprite_setScale(life.s, life.scale);
    sfSprite_setTexture(life.s, life.tab_life[life.index], sfTrue);
    data->cursor = curs;
    data->life = life;
    for (int i = 0; i != 4; i++)
        data->life.tab_life[i] = life.tab_life[i];
    data->heart_s = heart_s;
}

void init_clock_data(data_st *data)
{
    clock_st clock_fish;
    clock_st clock_ship;
    clock_st clock_create_f;
    clock_st *tab_clock = malloc(sizeof(clock_st) * 3);

    init_clock(&clock_fish);
    init_clock(&clock_ship);
    init_clock(&clock_create_f);
    tab_clock[0] = clock_fish;
    tab_clock[1] = clock_ship;
    tab_clock[2] = clock_create_f;
    data->tab_clock = tab_clock;
}