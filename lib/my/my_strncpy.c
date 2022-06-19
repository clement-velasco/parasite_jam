/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strncpy
*/

int my_strlen(char const *src);

char *my_strncpy(char *dest , char  const *src , int n)
{
    int len_src = my_strlen(src);

    for (int i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (n > len_src)
        dest[len_src] = '\0';
    return dest;
}
