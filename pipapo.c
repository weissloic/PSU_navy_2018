/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** ee
*/
#include "include/my.h"

void cpy_first_letter(int *number, char *letter, navy_t *navy, char **pos)
{
    for (int i = 0; i != 4; i++) {
        for (int y = 0; y != 8; y++) {
            if (pos[i][1] == letter[y]) {
                navy->value_one[0][i] = number[y];
            }
            navy->value_one[1][i] = my_getarraynbr(pos[i], 2);
        }
    }
}

void cpy_second_letter(int *number, char *letter, navy_t *navy, char **pos)
{
    for (int i = 0; i != 4; i++) {
        for (int y = 0; y != 8; y++) {
            if (pos[i][3] == letter[y]) {
                navy->value_two[0][i] = number[y];
            }
            navy->value_two[1][i] = my_getarraynbr(pos[i], 4);
        }
    }
}

char **cpy_array(char **position, char **map)
{
    int o = 0;
    int test = 0;

    for (int i = 0; i != 4; i++) {
        for (test = 0; test != 8; test++) {
            if (map[i][test] == ':') {
                test++;
            }
            position[i][o] = map[i][test];
            o++;
        }
        o = 0;
    }
    return (position);
}

int my_getarraynbr(char *str, int nbr)
{
    int i = 0;
    int n = 0;

    if (str[0] == '-' && str[1] != 0) {
        i++;
    }
    for (i = nbr ; i != nbr + 1; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            n = n + str[i] - 48;
            n = n * 10;
        }
    }
    n /= 10;
    if (str[0] == ' ') {
        return (n * -1);
    } else {
        return (n);
    }
}

int put_my_boats(navy_t *navy, char **tab)
{
    first_blocks(navy, '2', 0);
    first_boat(navy, '2', 0);
    first_blocks(navy, '3', 1);
    first_boat(navy, '3', 1);
    first_blocks(navy, '4', 2);
    first_boat(navy, '4', 2);
    first_blocks(navy, '5', 3);
    first_boat(navy, '5', 3);
}