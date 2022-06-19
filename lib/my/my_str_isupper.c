/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_str_is_upper
*/

int my_str_isupper(char  const *str)
{
    int test = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            test++;
        if (test == 0)
            return 0;
        test = 0;
    }
    return 1;
}
