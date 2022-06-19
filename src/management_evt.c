/*
** EPITECH PROJECT, 2022
** parasite
** File description:
** management_evt
*/

#include "my.h"
#include "parasite.h"

static int init[] = {0, 1920, 0, 1080};

static sfVector2f (*fonc[])(sfVector2f, int) = {&move_a, &move_b,
&move_c, &move_d};

static sfVector2f def_pos(void)
{
    sfVector2f pos;
    int nb = calc_rand_nb(4);

    if (nb == 0 || nb == 1) {
        pos.x = init[nb];
        pos.y = calc_rand_nb(1080);
        return pos;
    }
    pos.y = init[nb];
    pos.x = calc_rand_nb(1920);
    return pos;
}

static obj_t *add_enemy(obj_t *prev, add_t add, char **conf)
{
    obj_t *new = malloc(sizeof(obj_t));
    info_sprite_t *info = search_info("$enemy_para", conf);
    obj_t *tmp = prev;
    sfVector2f pos = def_pos();

    if (new == NULL)
        return NULL;
    new = set_elem(NULL, info->filename, pos, info->scale);
    sfSprite_setScale(new->sprite, (sfVector2f) {0.5, 0.5});
    new->move = set_fonc_move(new->pos);
    new->option.value = 5;
    new->next = NULL;
    if (prev == NULL)
        return new;
    while (prev->next)
        prev = prev->next;
    prev->next = new;
    return tmp;
}

static  move_enemy(obj_t *obj, int value)
{
    obj_t *tmp = obj;

    while (obj) {
        obj->pos = obj->move(obj->pos, value);
        sfSprite_setPosition(obj->sprite, obj->pos);
        obj = obj->next;
    }
    return tmp;
}

obj_t *management_evt(all_clock_t *clock, all_obj_t *obj, char **conf)
{
    add_t add = obj->add;

    clock->usage.sec = clock->time.microseconds / 1000000.0;
    clock->add.sec = clock->time.microseconds / 1000000.0;
    clock->move_n.sec = clock->time.microseconds / 1000000.0;
    clock->rec.sec = clock->time.microseconds / 1000000.0;
    if (clock->usage.sec >= clock->usage.ref)
        obj->info->option.value = 1;
    if (clock->move_n.sec >= clock->move_n.ref) {
        obj->enemy = move_enemy(obj->enemy, add.speed);
        clock->anime.ref = clock->anime.sec + 0.15;
    }
    if (clock->add.sec >= clock->add.ref) {
        obj->enemy = add_enemy(obj->enemy, add, conf);
        clock->add.ref = clock->add.sec + add.time;
    }
    if (clock->rec.sec >= clock->rec.ref) {
        add.speed += 5;
        add.time -= 0.25;
        clock->rec.ref = clock->rec.sec + 3;
    }
    return obj->enemy;
}