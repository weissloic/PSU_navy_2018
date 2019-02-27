/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** possitions errors
*/
#include "include/my.h"

int horizontal_positions(char **tab)
{
    int pos1;
    int pos2;
    int pos3;

    for (int i = 0; i != 4; i++) {
        if (tab[i][2] != tab[i][5]) {
            pos1 = tab[i][2];
            pos2 = tab[i][5];
            pos3 = pos2 - pos1;
            if (pos3 + 1 != my_get_nboatr(tab[i])) {
                return (84);
            }
        }
    }
}

int my_get_nboatr(char *str)
{
    int i = 0;
    int n = 0;

    if (str[0] == '-' && str[1] != 0) {
        i++;
    }
    for (i; i != 1; i++) {
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

int vertical_positions(char **tab)
{
    int pos1;
    int pos2;
    int pos3;

    for (int i = 0; i != 4; i++) {
        if (tab[i][3] != tab[i][6]) {
            pos1 = tab[i][3];
            pos2 = tab[i][6];
            pos3 = pos2 - pos1;
            if (pos3 + 1 != my_get_nboatr(tab[i])) {
                return (84);
            }
        }
    }
}

int diagonal_positions(char **tab)
{
    for (int i = 0; i != 4; i++) {
        if (tab[i][3] != tab[i][6] && tab[i][2] != tab[i][5]) {
            return (84);
        }
    }
}