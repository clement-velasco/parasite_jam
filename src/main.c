/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/

#include "my.h"
#include "parasite.h"

int main(int argc, char const **argv, char **env)
{
    if (env[0] == NULL)
        return ERROR;
    if (parasite() == ERROR)
        return ERROR;
    return 0;
}