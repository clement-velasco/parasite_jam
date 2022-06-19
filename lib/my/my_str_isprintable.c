/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    int test = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126)
            test++;
        if (test == 0)
            return 0;
        test = 0;
    }
    return 1;
}
