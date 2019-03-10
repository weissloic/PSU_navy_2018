/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** gnl 3
*/
#include "../../include/my.h"

char *str_concat(char *str1, char *str2, int start_cpy, int stop_cpy)
{
    static int full = 0;
    char *str3 = NULL;
    int strnbr = 0;
    int start = 0;

    str3 = malloc(sizeof(char) * nb_alloc(str1, str2, stop_cpy));
    if (str1 != NULL) {
        for (start = 0; str1[start] != '\0'; start += 1)
            str3[start] = str1[start];
    }
    full = start;
    for (strnbr = start_cpy; str2[strnbr] != '\0' &&
    strnbr < stop_cpy; strnbr += 1\
    , full += 1)
        str3[full] = str2[strnbr];
    str3[full] = '\0';
    free(str1);
    return str3;
}

static int nb_alloc(char *str1, char *str2, int cpy)
{
    int full = 0;
    int strnbr = 0;

    if (str1 != NULL) {
        while (str1[full] != '\0')
            full += 1;
    }
    while (str2[strnbr] != '\0' && strnbr < cpy) {
        strnbr += 1;
    }
    return (strnbr + full + 1);
}