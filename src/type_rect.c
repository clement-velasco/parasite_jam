/*
** EPITECH PROJECT, 2022
** rect rpg
** File description:
** rpg
*/

#include "parasite.h"


void move_player(obj_t *perso, sfEvent *event)
{
    int *tab = perso->rect_value;
    sfIntRect rect = perso->rect;


    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyRight) {
        perso->rect.top = tab[7];
        perso->rect.left = tab[8];
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyLeft) {
        perso->rect.top = tab[9];
        perso->rect.left = tab[10];
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyUp) {
        perso->rect.top = tab[5];
        perso->rect.left = tab[6];
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyDown) {
         perso->rect.top = tab[3];
        perso->rect.left = tab[4];
    }
}






















