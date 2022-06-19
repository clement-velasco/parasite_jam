/*
** EPITECH PROJECT, 2021
** day07
** File description:
** my_strncat
*/

int my_strlen(char *str);

char *my_strncat(char *dest , char  const *src, int nb)
{
    int len_dest = my_strlen(dest);

    for (int i = 0; i < nb && src[i] != '\0'; i++) {
        dest[len_dest] = src[i];
        len_dest++;
    }
    dest[len_dest] = '\0';
    return dest;
}
