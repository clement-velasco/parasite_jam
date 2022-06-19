/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** concat_strings
*/

#include "my.h"

char *concat_strings(char *directory, char *filename)
{
    int len = my_strlen(directory) + my_strlen(filename);
    char *concat = malloc(sizeof(char) * (len + 1));
    int index = 0;

    if (concat == NULL)
        return NULL;
    for (; directory[index]; index++)
        concat[index] = directory[index];
    for (int i = 0; filename[i]; i++) {
        concat[index] = filename[i];
        index += 1;
    }
    concat[index] = '\0';
    return concat;
}
