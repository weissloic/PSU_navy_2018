/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** gnl 1
*/
#include "../../include/my.h"

char *get_next_line(int fd)
{
    static char str[READ_SIZE];
    static int retline = READ_SIZE;
    char *full_str = NULL;
    int nb = READ_SIZE;

    if (fd == -1)
        return NULL;
    if (retline != READ_SIZE)
        full_str = manage_str(full_str, str , &retline);
    while (retline == READ_SIZE) {
        nb = read(fd, str, READ_SIZE);
        if (nb == 0)
            return NULL;
        retline = find_retline(str, 0, nb);
        full_str = str_concat(full_str, str, 0, (retline < nb ) ? \
        retline : nb);
    }
    if (nb < READ_SIZE)
        retline = READ_SIZE;
    return full_str;
}

static int find_retline(char *str, int first, int size)
{
    int a = first;

    while (a < size) {
        if (str[a] == '\n')
            return a;
        a += 1;
    }
    return size;
}

static char *manage_str(char *str1, char *str2, int *line)
{
    str1 = str_concat(str1, str2, *line + 1, find_retline(str2, \
    *line + 1, READ_SIZE));
    *line = find_retline(str2, *line + 1, READ_SIZE);
    return str1;
}