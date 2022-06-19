/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int pt = my_strlen(str);
    int len = pt;
    char a;
    int i = 0;

    while (len != pt / 2) {
        a = str[i];
        str[i] = str[len - 1];
        str[len - 1] = a;
        len--;
        i++;
    }
    return str;
}
