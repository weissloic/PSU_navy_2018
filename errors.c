/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** errors
*/
#include "include/my.h"

int check_boats(char **tab)
{
    for (int i = 0; i != 4; i++) {
        if (tab[i][0] == 50 || tab[i][0] == 51 || tab[i][0] == 
        52 || tab[i][0] == 53) {
        } else {
            return (84);
        }
    }
}

int check_points(char **tab)
{
    for (int i = 0; i != 4; i++) {
        if (tab[i][1] != ':' || tab[i][4] != ':') {
            return (84);
        }
    }
}

int check_first(char **tab)
{
    for (int i = 0; i != 4; i++) {
        if (tab[i][2] >= 'A' && tab[i][2] <= 'H') {
            horizontal_positions(tab);
        } else {
            return (84);
        }
    }
}

int check_errors(char **tab)
{
    if (check_boats(tab) == 84) {
        return (84);
    }
    if (check_points(tab) == 84) {
        return (84);
    }
    if (check_first(tab) == 84) {
        return (84);
    }
    if (check_final_square(tab)== 84) {
        return (84);
    }
    if (diagonal_positions(tab) == 84) {
        return (84);
    }
}