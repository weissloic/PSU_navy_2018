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

        if (tab[i][0] == 50 || tab[i][0] == 51 || tab[i][0] == 52 || tab[i][0] == 53) {
        } else {
            return (84);
        }
    }
}

int check_points(char **tab)
{
    for (int i = 0; i != 4; i++) {
        if (tab[i][1] != ':' || tab[i][4] != ':') {
            printf("ok2\n");
            return (84);
        }
    }  
}

int check_first(char **tab)
{
    for (int i = 0; i != 4; i++) {
        if (tab[i][2] > 'A' && tab[i][2] < 'H' || tab[i][5] > 'A' && tab[i][5] < 'H') {
        } else {
            return (84);
        }
    }
}

int check_last(char **tab)
{
    for (int i = 0; i != 3; i++) {
        if (tab[i][3] > 49 && tab[i][3] < 56 || tab[i][6] > 49 && tab[i][6] < 56) {
            printf("%c\n", tab[i][3]);
        } else {
            printf("okkk\n");
            return (84);
        }
    }
}

int check_errors(char **tab)
{
    if (check_boats(tab) == 84) {
        return (84);
    }
    check_points(tab);
    check_first(tab);
    check_last(tab);
}