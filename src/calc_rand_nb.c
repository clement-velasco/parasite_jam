/*
** EPITECH PROJECT, 2022
** parasite
** File description:
** calc_rand_nb
*/

#include <time.h>
#include "my.h"
#include "parasite.h"

int calc_rand_nb(int max)
{
    int random = 0;

    srand(time(NULL));
    random = rand() % max;
    return random;
}