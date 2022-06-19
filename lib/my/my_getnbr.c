/*
** EPITECH PROJECT, 2021
** day04
** File description:
** my_getnbr
*/

#include <stdio.h>

int test_pos(char const *str);

int my_strlen(char const *str);

static int my_strlen_getnbr(char const *str)
{
    int i = 0;
    int c = 0;

    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9') && c != 0)
            return c;
        if (str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9') && c != 0)
            return c;
        if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
            c++;
        if (str[i] >= '0' && str[i] <= '9')
            c++;
        i++;
    }
    return c;
}

static int clc_mult(char const *str, int len, int indice)
{
    int mult = 1;

    if (str[indice] == '-')
        len = len - 1;
    while (len != 1) {
        mult = mult * 10;
        len--;
    }
    return mult;
}

int clc_indice(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
            return i;
        if (str[i] >= '0' && str[i] <= '9')
            return i;
        i++;
    }
    return 0;
}

static int test_err(char const *str)
{
    int err = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            err++;
    }
    if (err == 1)
        return 0;
    if ((err = test_pos(str)) != 0)
        return 0;
    return 0;
}

int my_getnbr(char const *str)
{
    int len = my_strlen_getnbr(str);
    int nb = 0;
    int indice = clc_indice(str);
    int  mult = clc_mult(str, len, indice);
    int sign = 1;

    if ((nb = test_err(str)) != 0)
        return 404;
    if (str[indice] == '-') {
        sign = -1;
        indice = indice + 1;
    }
    while (mult != 1) {
        nb = nb + (str[indice] - 48) * mult;
        mult = mult / 10;
        indice++;
    }
    nb = nb + (str[indice] - 48) * mult;
    nb = nb * sign;
    return nb;
}
