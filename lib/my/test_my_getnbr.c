/*
** EPITECH PROJECT, 2021
** day04
** File description:
** test_my_getnbr
*/

int clc_indice(char const *str);

int my_strlen(char const *str);

static int test_suite(char const *str)
{
    int suite = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            suite++;
        if ((str[i] < '0' || str[i] > '9') && suite != 0)
            return suite;
    }
    return suite;
}

static int test_pos_two(char const *str, int start)
{
    if (str[start + 4] > '4')
        return 84;
    if (str[start + 5] > '8')
        return 84;
    if (str[start + 6] > '3')
        return 84;
    if (str[start + 7] > '6')
        return 84;
    if (str[start + 8] > '4')
        return 84;
    if (str[start + 9] > '7')
        return 84;
    if (str[start + 9] == '9')
        return 84;
    return 0;
}

int test_pos(char const *str)
{
    int len = my_strlen(str);
    int suite = test_suite(str);
    int start = clc_indice(str);

    if (suite > 10)
        return 84;
    if (suite < 10)
        return 0;
    if (str[start] == '-')
        start++;
    if (str[start] > '2')
        return 84;
    if (str[start + 1] > '1')
        return 84;
    if (str[start + 2] > '4')
        return 84;
    if (str[start + 3] > '7')
        return 84;
    len = test_pos_two(str, start);
    return len;
}
