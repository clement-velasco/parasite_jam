/*
** EPITECH PROJECT, 2021
** day03
** File description:
** my_isneg
*/

void my_putchar(char c);

int  my_isneg(int nb)
{
    if (nb >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return 0;
}
