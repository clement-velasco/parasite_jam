/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strncmp
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i != n) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}
