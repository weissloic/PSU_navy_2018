/*
** EPITECH PROJECT, 2018
** my_put_unbr.c
** File description:
** my_put_nbr w/ unsigned int
*/
#include "../../include/my.h"

long my_put_long_nbr(long nb)
{
    if (nb > 0) {
        my_put_long_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return (0);
}
