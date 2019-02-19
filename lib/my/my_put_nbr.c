/*
** EPITECH PROJECT, 2018
** my_print_comb2
** File description:
** my print comb 2
*/
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb == 0)
        my_putchar('0');
    else if (nb >  0 && nb < 10)
        my_putchar(nb % 10 + 48);
    else {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}
