/*
** EPITECH PROJECT, 2022
** parasite
** File description:
** init_obj_intro
*/

#include "my.h"
#include "parasite.h"

obj_t *init_map_intro(char **conf)
{
    info_sprite_t *info = search_info("$map_intro", conf);
    obj_t *new = set_elem(NULL, info->filename, info->pos, info->scale);

    free_info(info);
    return new;
}

obj_t *init_para_intro(char **conf)
{
    info_sprite_t *info = search_info("$parasite", conf);
    obj_t *cho = set_elem(NULL, info->filename, info->pos, info->scale);
    int *tmp = info->rect;

    cho->rect = (sfIntRect) {tmp[3], tmp[4], tmp[0], tmp[1]};
    sfSprite_setTextureRect(cho->sprite, cho->rect);
    cho->stat.speed = info->stat[0];
    cho->stat.life = info->stat[1];
    cho->rect_value = copy_tab(tmp);
    cho->rect_value = copy_tab(tmp);
    free_info(info);
    return cho;
}

obj_t *init_shape_intro(char **conf)
{
    info_sprite_t *info = search_info("$perso_intro", conf);
    obj_t *mtr = set_elem(NULL, info->filename, info->pos, info->scale);

    mtr->rect = (sfIntRect) {250, 50, 100, 200};
    free_info(info);
    return mtr;
}

all_obj_t *init_obj_intro(char **conf)
{
    all_obj_t *all = malloc(sizeof(all_obj_t));

    if (all == NULL)
        return NULL;
    all->background = init_map_intro(conf);
    all->cho_gath = init_para_intro(conf);
    all->enemy = init_shape_intro(conf);
    all->info = init_info_intro(conf);
    all->quest = init_quest_intro(conf);
    return all;
}