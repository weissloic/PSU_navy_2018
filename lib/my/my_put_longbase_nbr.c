/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** long base
*/
#include "../../include/my.h"

long my_put_longbase_nbr(unsigned int nbr, char *base)
{
    int len_base = my_strlen(base);

    my_putstr("0x7fff");
    if (nbr == 0) {
        return (0);
    } else if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
    } else {
        convert_tobase(nbr / len_base, base);
    }
    my_putchar(base[nbr % len_base]);
    return (0);
}