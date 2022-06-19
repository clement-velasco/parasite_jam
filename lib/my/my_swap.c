/*
** EPITECH PROJECT, 2021
** day04
** File description:
** my_swap.c
*/

int my_swap(int *a, int *b)
{
    int cpy = *b;

    *b = *a;
    *a = cpy;
    return 0;
}
