/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strcmp
*/

int my_strlen(char const *str);

int  my_strcmp(char  const *s1 , char  const *s2)
{
    int len_a = my_strlen(s1);
    int len_b = my_strlen(s2);
    int i = 0;

    if (len_a < len_b)
        return 1;
    if (len_b < len_a)
        return -1;
    while (s1[i] != '\0') {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}
