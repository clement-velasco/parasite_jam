/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free_info
*/

#include "my.h"
#include "parasite.h"

void free_info(info_sprite_t *info)
{
    free(info->filename);
    if (info->rect != NULL)
        free(info->rect);
    if (info->stat != NULL)
        free(info->stat);
    free(info);
}