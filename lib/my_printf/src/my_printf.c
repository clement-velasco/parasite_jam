/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include "my.h"

static info_t set_info(void)
{
    info_t info;

    info.index = 0;
    info.nb_cara = 0;
    info.precision = 1;
    return info;
}

int my_printf(char *format, ...)
{
    info_t info = set_info();
    va_list ap;

    va_start(ap, format);
    while (format[info.index] != '\0') {
        if (format[info.index] != '%') {
            my_putchar(format[info.index]);
            info.nb_cara ++;
        }
        if (format[info.index] == '%') {
            info = print_arg(format, info, ap);
        }
        info.index ++;
    }
    va_end(ap);
    return info.nb_cara;
}
