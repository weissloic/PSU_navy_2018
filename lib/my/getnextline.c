/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** GNL
*/

#include "../../include/my.h"

static int find_retline(char *str, int start, int size)
{
    int i = start;

    while (i < size) {
        if (str[i] == '\n')
            return i;
        i += 1;
    }
    return size;
}

static int nb_alloc(char *full_str, char *str, int stop_cpy)
{
    int i_full = 0;
    int i_str = 0;

    if (full_str != NULL) {
        while (full_str[i_full] != '\0')
            i_full += 1;
    }
    while (str[i_str] != '\0' && i_str < stop_cpy) {
        i_str += 1;
    }
    return (i_str + i_full + 1);
}

char *str_concat(char *full_str, char *str, int start_cpy, int stop_cpy)
{
    static int i_full = 0;
    char *ret_str = NULL;
    int i_str = 0;
    int i_start = 0;

    ret_str = malloc(sizeof(char) * nb_alloc(full_str, str, stop_cpy));
    if (full_str != NULL) {
        for (i_start = 0; full_str[i_start] != '\0'; i_start += 1)
            ret_str[i_start] = full_str[i_start];
    }
    i_full = i_start;
    for (i_str = start_cpy; str[i_str] != '\0' && i_str < stop_cpy; i_str += 1\
    , i_full += 1)
        ret_str[i_full] = str[i_str];
    ret_str[i_full] = '\0';
    free(full_str);
    return ret_str;
}

static char *manage_str(char *full_str, char *str, int *idx_retline)
{
    full_str = str_concat(full_str, str, *idx_retline + 1, find_retline(str, \
    *idx_retline + 1, READ_SIZE));
    *idx_retline = find_retline(str, *idx_retline + 1, READ_SIZE);
    return full_str;
}

char *get_next_line(int fd)
{
    static char str[READ_SIZE];
    static int idx_retline = READ_SIZE;
    char *full_str = NULL;
    int nb = READ_SIZE;

    if (fd == -1)
        return NULL;
    if (idx_retline != READ_SIZE)
        full_str = manage_str(full_str, str , &idx_retline);
    while (idx_retline == READ_SIZE) {
        nb = read(fd, str, READ_SIZE);
        if (nb == 0)
            return NULL;
        idx_retline = find_retline(str, 0, nb);
        full_str = str_concat(full_str, str, 0, (idx_retline < nb ) ? \
        idx_retline : nb);
    }
    if (nb < READ_SIZE)
        idx_retline = READ_SIZE;
    return full_str;
}