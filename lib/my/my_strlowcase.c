/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strlowcase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] >= 'A' && str[i] <= 'Z'))
            str[i] = str[i] - '0';
        i++;
    }
    return str;
}
