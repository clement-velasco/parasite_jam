/*
** EPITECH PROJECT, 2021
** day05
** File description:
** my_compute_square.c
*/

int my_compute_square_root(int nb)
{
    int res = 0;

    if (nb < 0)
        return 0;
    if (nb == 1)
        return 1;
    while (res < nb) {
        if (res * res == nb)
            return res;
        res++;
    }
    return 0;
}
