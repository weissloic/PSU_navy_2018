/*
** EPITECH PROJECT, 2018
** convert_to
** File description:
** bases
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"

int convert_tobase(int nbr, char *base)
{
    int len_base = my_strlen(base);

    if (nbr == 0) {
        return (0);
    } else if (nbr > 0) {
        convert_tobase(nbr / len_base, base);
    }
    my_putchar(base[nbr % len_base]);
    return (0);
}

void convert_to_bin(va_list ap)
{
    convert_tobase(va_arg(ap, int), "01");
}

void convert_to_octo(va_list ap)
{
    convert_tobase(va_arg(ap, int), "01234567");
}

void convert_to_hexa(va_list ap)
{
    convert_tobase(va_arg(ap, int), "0123456789abcdef");
}

void convert_to_mhexa(va_list ap)
{
    convert_tobase(va_arg(ap, int), "0123456789ABCDEF");
}