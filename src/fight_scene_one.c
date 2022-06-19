/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fight_scene_one
*/

#include "my.h"
#include "parasite.h"

static int is_overlap_fight(sfRenderWindow *win, obj_t *obj)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    int i = 0;

    while (obj) {
        if (i == 2)
            return 0;
        if (sfFloatRect_contains(&obj->collider, mouse.x, mouse.y)) {
            sfSprite_setColor(obj->sprite, sfBlue);
            return obj->option.type;
        }
        else
            sfSprite_setColor(obj->sprite, sfWhite);
        obj = obj->next;
        i += 1;
    }
    return 0;
}

static int analyse_fight(sfRenderWindow *win, all_obj_t *obj, obj_t *button)
{
    int stat = is_overlap_fight(win, button);

    if (stat != 0 && sfMouse_isButtonPressed(sfMouseLeft)) {
        obj->enemy->stat.life -= obj->cho_gath->stat.atk;
        return 2;
    }
    return 0;
}

static int test_tour_player(all_obj_t *obj, obj_t *button, int option, sfRenderWindow *win)
{
    obj_t *cho = obj->cho_gath;
    obj_t *mtr = obj->enemy;
    int stat = cho->stat.speed - mtr->stat.speed;

    if (cho->stat.life <= 0)
        return 1;
    if (mtr->stat.life <= 0)
        return 2;
    if (stat < 1 && option == 1)
        attack_generic(mtr, cho, win, button);
    if (stat < 1 && option == 2)
        attack_generic(mtr, cho, win, button);
    return 0;
}

static int game_loop_atk(sfRenderWindow *win, all_obj_t *obj, obj_t *button, char **conf)
{
    int stat = 0;
    int option = 0;
    sfEvent evt;

    stat = test_tour_player(obj, button, option, win);
    if (stat != 0)
        return stat;
    while (sfRenderWindow_pollEvent(win, &evt)) {
        check_exit(evt, win, obj, conf);
        option = analyse_fight(win, obj, button);
    }
    stat = test_tour_player(obj, button, option, win);
    if (stat != 0)
        return stat;
    if (option == 2)
        option = 1;
    return stat;
}

static void display_fight_one(sfRenderWindow *win, all_obj_t *obj, obj_t *button, text_t *text)
{
    display(win, button);
    display(win, obj->cho_gath);
    display(win, obj->enemy);
    display_text(win, text);
    sfRenderWindow_display(win);
}

void fight_scene_one(sfRenderWindow *win, all_obj_t *obj, char **conf)
{
    obj_t *button = init_obj_fight(conf);
    text_t *text = init_text_button(button);
    int stat = 0;

    sfSprite_setScale(button->next->next->sprite, (sfVector2f) {1.6, 1.2});
    set_pos_fight(obj->cho_gath, obj->enemy, 0);
    while (sfRenderWindow_isOpen(win) && stat == 0) {
        sfRenderWindow_clear(win, sfRed);
        stat = game_loop_atk(win, obj, button, conf);
        display_fight_one(win, obj, button, text);
    }
    set_pos_fight(obj->cho_gath, obj->enemy, 1);
    free_text(text);
    free_obj(button);
}
