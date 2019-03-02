/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** ee
*/
#include "include/my.h"

void cpy_first_letter(int *contains_number, char *contains_letter, navy_t *navy, char **position)
{
    for (int i = 0; i != 4; i++) {
        for (int y = 0; y != 8; y++) {
            if (position[i][1] == contains_letter[y]) {
                navy->value_one[0][i] = contains_number[y];
            }
            navy->value_one[1][i] = my_getarraynbr(position[i], 2);
        }
    }
}

void cpy_second_letter(int *contains_number, char *contains_letter, navy_t *navy, char **position)
{
    for (int i = 0; i != 4; i++) {
        for (int y = 0; y != 8; y++) {
            if (position[i][3] == contains_letter[y]) {
                navy->value_two[0][i] = contains_number[y];
            }
            navy->value_two[1][i] = my_getarraynbr(position[i], 4);
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