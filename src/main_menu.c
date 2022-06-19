/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main_menu
*/

#include "my.h"
#include "parasite.h"

static int test_option(sfRenderWindow *win, int stat)
{
    if (stat == 2)
        sfRenderWindow_close(win);
    return 1;
}

static int analyse_events_menu(sfRenderWindow *win, sfEvent evt, obj_t *obj)
{
    int stat = is_overlap(win, obj);
    int number = 0;

    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(win);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win);
    if (stat != 0 && sfMouse_isButtonPressed(sfMouseLeft))
        number = test_option(win, stat);
    return number;
}

static obj_t *init_obj_main_menu(void)
{
    obj_t *obj = set_elem(NULL, "assets/start_button.png", (sfVector2f)
    {755, 200}, (sfVector2f) {0.5, 0.5});
    obj_t *tmp = NULL;

    obj = set_elem(obj, "assets/exit_button.png", (sfVector2f)
    {755, 680}, (sfVector2f) {0.5, 0.5});
    tmp = obj;
    for (int i = 1; i <= 2; i++) {
        obj->option.type = i;
        obj->option.value = i;
        obj = obj->next;
    }
    return tmp;
}

int main_menu(sfRenderWindow *win)
{
    sfEvent event;
    obj_t *obj = init_obj_main_menu();
    obj_t *background = set_elem(NULL, "assets/backpara.jpg", (sfVector2f)
    {0, 0}, (sfVector2f) {3, 3});
    int n1 = 0;

    if (background == NULL)
        return ERROR;
    sfRenderWindow_clear(win, sfWhite);
    while (sfRenderWindow_isOpen(win) && n1 == 0) {
        while (sfRenderWindow_pollEvent(win, &event))
            n1 = analyse_events_menu(win, event, obj);
        display(win, background);
        display(win, obj);
        sfRenderWindow_display(win);
    }
    free_obj(obj);
    return 2;
}