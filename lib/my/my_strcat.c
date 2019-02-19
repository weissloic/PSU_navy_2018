/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/
#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = 0;

    while (dest[a] != '\0')
        a++;
    while (src[b] != '\0') {
        dest[a + b] = src[b];
        b++;
    }
    dest[a + b] = '\0';
    return (dest);
}