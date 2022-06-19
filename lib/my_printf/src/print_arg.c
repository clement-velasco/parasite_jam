/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** print_arg
*/

#include <stdlib.h>
#include "my.h"

static int clc_prec(info_t info, char *format)
{
    char *res = NULL;
    int len = 0;
    int c = 0;

    if (format[info.index + 1] != '.')
        return 0;
    for (int i = info.index + 2; format[i] >= '0' && format[i] <= '9'; i++)
        len ++;
    res = malloc(sizeof(char) * (len + 1));
    for (int i = info.index + 2; format[i] >= '0' && format[i] <= '9'; i++) {
        res[c] = format[i];
        c ++;
    }
    res[c] = '\0';
    c = my_getnbr(res);
    free(res);
    return c;
}

info_t print_arg(char *format, info_t info, va_list ap)
{
    int prec = clc_prec(info, format);
    info_t (*flags[3])(info_t, va_list) = {&flags_d, &flags_s, &flags_c};
    char str[3] = {'d', 's', 'c'};

    for (int i = info.index; format[i] == '%' || format[i] == '.'; i++)
        info.index += 1;
    for (int i = info.index; format[i] >= '0' && format[i] <= '9'; i++)
        info.index += 1;
    info.precision = prec;
    for (int i = 0; i < 3; i++) {
        if (format[info.index] == str[i])
            info = (*flags[i])(info, ap);
    }
    info.precision = 1;
    return info;
}
