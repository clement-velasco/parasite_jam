/*
** EPITECH PROJECT, 2021
** lib
** File description:
** free_array
*/

#include <stddef.h>
#include <stdlib.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
}
