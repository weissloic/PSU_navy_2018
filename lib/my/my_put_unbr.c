/*
** EPITECH PROJECT, 2018
** my_put_unbr.c
** File description:
** my_put_nbr w/ unsigned int
*/
#include "../../include/my.h"

unsigned int my_put_unsigned_nbr(unsigned int nb)
{
    if (nb > 0) {
        my_put_unsigned_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    } else if (nb < 0) {
        return (0);
    }
    return (0);
}
