/*
** EPITECH PROJECT, 2021
** day05
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb , int p)
{
    int res = nb;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p != 1) {
        res = res * my_compute_power_rec(nb, p - 1);
    }
    return res;
}
