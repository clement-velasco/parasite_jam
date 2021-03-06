/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strcpy
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);

    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}
