/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_obj
*/

#include "my.h"
#include "parasite.h"

obj_t *init_map_one(char **conf)
{
    info_sprite_t *info = search_info("$red_map", conf);
    obj_t *new = set_elem(NULL, info->filename, info->pos, info->scale);

    free_info(info);
    return new;
}

all_obj_t *init_obj(char **conf)
{
    all_obj_t *all = malloc(sizeof(all_obj_t));

    if (all == NULL)
        return NULL;
    all->add = (add_t) {5, 3};
    all->background = init_map_one(conf);
    all->cho_gath = init_para_intro(conf);
    all->enemy = NULL;
    all->info = init_info_intro(conf);
    all->quest = init_quest_game(conf);
    return all;
}