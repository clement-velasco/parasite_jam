/*
** EPITECH PROJECT, 2022
** parasite
** File description:
** init_info_intro
*/

#include "my.h"
#include "parasite.h"

text_t *init_quest_game(char **conf)
{
    char *text = open_file("info_text/text_game.txt");
    text_t *new = malloc(sizeof(text_t));

    new->font = sfFont_createFromFile("assets/arcade.ttf");
    new->text = sfText_create();
    new->next = NULL;
    sfText_setFont(new->text, new->font);
    sfText_setString(new->text, text);
    sfText_setStyle(new->text, sfTextBold);
    sfText_setPosition(new->text, (sfVector2f) {1000, 100});
    sfText_setScale(new->text, (sfVector2f) {1, 1});
    sfText_setColor(new->text, sfBlack);
    return new;
}

text_t *init_quest_intro(char **conf)
{
    char *text = open_file("info_text/text_intro.txt");
    text_t *new = malloc(sizeof(text_t));

    new->font = sfFont_createFromFile("assets/arcade.ttf");
    new->text = sfText_create();
    new->next = NULL;
    sfText_setFont(new->text, new->font);
    sfText_setString(new->text, text);
    sfText_setStyle(new->text, sfTextBold);
    sfText_setPosition(new->text, (sfVector2f) {1000, 100});
    sfText_setScale(new->text, (sfVector2f) {1, 1});
    sfText_setColor(new->text, sfBlack);
    return new;
}

obj_t *init_info_intro(char **conf)
{
    info_sprite_t *info = search_info("$info_text", conf);
    obj_t *new = set_elem(NULL, info->filename, info->pos, info->scale);

    sfSprite_setScale(new->sprite, (sfVector2f) {0.7, 0.7});
    free_info(info);
    return new;
}

