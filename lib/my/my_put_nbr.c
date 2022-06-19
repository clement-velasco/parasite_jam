/*
** EPITECH PROJECT, 2021
** day03
** File description:
** my_put_nbr
*/

void my_putchar(char c);

static void print_int_max(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('7');
    return;
}

static void print_de_la_defaite(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_putchar('2');
        my_putchar('1');
        my_putchar('4');
        my_putchar('7');
        my_putchar('4');
        my_putchar('8');
        my_putchar('3');
        my_putchar('6');
        my_putchar('4');
        my_putchar('8');
        return;
    }
    print_int_max();
    return;
}

int my_put_nbr(int nb)
{
    if (nb == 2147483647 || nb == -2147483648) {
        print_de_la_defaite(nb);
        return 0;
    }
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar((nb % 10) + 48);
    return 0;
}
