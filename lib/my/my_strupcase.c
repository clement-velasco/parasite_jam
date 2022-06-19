/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] = str[i] - '0';
        i++;
    }
    return str;
}
