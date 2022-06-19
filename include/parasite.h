/*
** EPITECH PROJECT, 2021
** graph
** File description:
** my_rpg
*/

#ifndef parasite_H_
    #define parasite_H_

    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <errno.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    #define ERROR           84
    #define TRUE            1
    #define FALSE           0

typedef struct info_sprite_s {
    char        *filename;
    sfVector2f  pos;
    sfVector2f  scale;
    int         *rect;
    int         *stat;
} info_sprite_t;

typedef struct option_s {
    int type;
    int value;
    int move;
} option_t;

typedef struct stat_s {
    int atk;
    int def;
    int speed;
    int life;
} stat_t;

typedef struct add_s {
    int speed;
    int time;
} add_t;

typedef struct level_s {
    int num;
    int res;
    int upgrade;
} level_t;

typedef struct obj_s {
    sfText          *text;
    sfTexture       *texture;
    sfSprite        *sprite;
    sfFloatRect     collider;
    sfIntRect       rect;
    sfVector2f      pos;
    sfVector2f      scale;
    sfVector2f (*move) (sfVector2f, int);
    void (*fonc) (struct obj_s *, struct obj_s *, struct obj_s *, sfRenderWindow *);
    int             *rect_value;
    option_t        option;
    stat_t          stat;
    struct obj_s    *next;
} obj_t;


typedef struct collider_obj_s {
    sfRectangleShape        *rect;
    sfFloatRect             collider;
    sfVector2f              pos;
    sfVector2f              scale;
    int                     option;
    struct collider_obj_s   *next;
} collider_obj_t;

typedef struct all_obj_s {
    collider_obj_t  *colliders;
    add_t           add;
    obj_t           *background;
    obj_t           *cho_gath;
    obj_t           *barre_xp;
    obj_t           *cinematic;
    obj_t           *enemy;
    obj_t           *info;
    struct text_s   *quest;
} all_obj_t;

typedef struct text_s {
    sfText          *text;
    sfFont          *font;
    sfTexture       *texture;
    sfFloatRect     collider;
    int (*fonc) (struct all_obj_s *);
    int             type;
    int             stat;
    struct text_s   *next;
} text_t;
typedef struct sec_info_s {
    float sec;
    float ref;
} sec_info_t;

typedef struct all_clock_s {
    sfClock    *clock;
    sfClock    *clock_err;
    sfTime     time;
    sfTime     time_err;
    sec_info_t anime;
    sec_info_t move;
    sec_info_t add;
    sec_info_t usage;
    sec_info_t move_n;
    sec_info_t rec;
} all_clock_t;

typedef struct cinematic_s {
    sfTexture       *cinematic_texture;
    sfSprite        *cinematic_sprite;
    sfClock         *cinematic_clock;
    sfVector2f      cinematic_pos;
    sfTime          cinematic_time;
} cinematic_t;

//INIT PROJ
int my_rpg(void);
int main_menu(sfRenderWindow *win);

//GAME MANAGEMENT
int parasite(void);
int intro_scene(sfRenderWindow *win, char **conf);
void display_interlude(sfRenderWindow *win);
obj_t *init_para_intro(char **conf);
obj_t *management_evt(all_clock_t *clock, all_obj_t *obj, char **conf);
int game_management(sfRenderWindow *win, char **conf);
obj_t *init_info_intro(char **conf);
int calc_rand_nb(int max);
int touch_enemy(sfRenderWindow *win, all_obj_t *obj);
void *set_fonc_move(sfVector2f pos);
void clock_management_intro(sfRenderWindow *win, all_clock_t *clock, all_obj_t *obj);
all_obj_t *init_obj_intro(char **conf);
text_t *init_quest_game(char **conf);
text_t *init_quest_intro(char **conf);
int analyse_events(sfRenderWindow *, sfEvent, all_obj_t *, char **);
void free_all_obj(all_obj_t *obj);
void free_obj(obj_t *obj);
void display_obj(sfRenderWindow *win, all_obj_t *obj);
void display(sfRenderWindow *win, obj_t *obj);
void clock_management(all_clock_t *clock, all_obj_t *obj);
int is_overlap(sfRenderWindow *win, obj_t *obj);
int is_touch(int stat, obj_t *obj);
char *int_to_string(int nb);
int *copy_tab(int *tab);
void mouv_map(obj_t *map, all_obj_t *obj);
char *test_nb_cara(char *str, char *test, int nb);
int *set_rect_or_stat(char *dos_conf, char *str_test, int size);
void pause_menu(sfRenderWindow *win, all_obj_t *obj, char **conf);
void test_cond_quest(all_obj_t *obj);
text_t *set_elem_text(text_t *new, char *text, sfVector2f pos, int type);
void display_text(sfRenderWindow *win, text_t *quest);
void free_text(text_t *obj);
void spe_one(obj_t *one, obj_t *cho, obj_t *button, sfRenderWindow *win);
void attack_generic(obj_t *one, obj_t *cho, sfRenderWindow *win,
obj_t *button);
void fight_scene_one(sfRenderWindow *win, all_obj_t *obj, char **conf);
text_t *set_new_text(text_t *prev, char *text, sfVector2f pos, int type);
void check_exit(sfEvent evt, sfRenderWindow *wn, all_obj_t *a, char **f);
void set_pos_fight(obj_t *cho, obj_t *mtr, int option);
int test_lose(all_obj_t *obj, sfRenderWindow *win);
void mouv_rect_cho(obj_t *cho);

//INIT FONCTION
info_sprite_t *search_info(char *key, char **dos_conf);
void free_info(info_sprite_t *info);
obj_t *set_elem(obj_t *prev, char *path, sfVector2f pos, sfVector2f scale);
all_obj_t *init_obj(char **conf);
collider_obj_t *init_collider_map_one(char **conf);
int *set_nb_in_tab(char *str);
text_t *init_quest(char **conf);
obj_t *init_enemy(char **conf);
obj_t *init_obj_fight(char **conf);
text_t *init_text_button(obj_t *button);

//MOVE_FONC
sfVector2f move_a(sfVector2f pos, int value);
sfVector2f move_b(sfVector2f pos, int value);
sfVector2f move_c(sfVector2f pos, int value);
sfVector2f move_d(sfVector2f pos, int value);

//QUEST MAP ONE
int quest_move(all_obj_t *obj);
int quest_rec_obj(all_obj_t *obj);
int quest_open_invente(all_obj_t *obj);
int quest_kill(all_obj_t *obj);
int quest_exit(all_obj_t *obj);

#endif /* parasite_H_ */
