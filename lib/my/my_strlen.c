/*
** EPITECH PROJECT, 2021
** day04
** File description:
** my_strlen.c
*/

int my_strlen(char *const str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
