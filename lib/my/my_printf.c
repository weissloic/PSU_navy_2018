/*
** EPITECH PROJECT, 2018
** Step2
** File description:
** Step2
*/
#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"

int my_printf(char *s, ...)
{
    int i = 0;
    int j = 0;
    int val = 0;
    char tb[9] = {'d', 'i', 'o', 'x', 'X', 'c', 's', 'b', '%'};
    va_list ap;

    va_start(ap, s);
    for (i; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            s++;
            for (j; j <= 10 && tb[j] != s[i]; j++);
                ptr1[j](ap);
        } else if (s[i] == '\n') {
            my_putchar('\n');
        } else {
            my_putchar(s[i]);
        }
    }
    va_end (ap);
}
