/*
** EPITECH PROJECT, 2018
** basics
** File description:
** string, caracter, int
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"

void display_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void display_string(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void display_int(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}