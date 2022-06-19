/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_str_isalpha.c
*/

int my_str_isalpha(char  const *str)
{
    int test = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            test++;
        if (str[i] >= 'a' && str[i] <= 'z')
            test++;
        if (test == 0)
            return 0;
        test = 0;
    }
    return 1;
}
