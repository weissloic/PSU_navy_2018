/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** final square check
*/
#include "include/my.h"

int check_last(char **tab)
{
    for (int i = 0; i != 4; i++) {
        if (tab[i][3] >= 49 && tab[i][3] <= 56) {
        } else {
            return (84);
        }
    }
}

int check_last_two(char **tab)
{
    for (int i = 0; i != 4; i++) {
        if (tab[i][6] >= 49 && tab[i][6] <= 56) {
        } else {
            return (84);
        }
    }
}

int check_lenght(char **tab)
{
    for (int i = 0; i != 4; i++) {
        if (my_strlen(tab[i]) != 7)
            return (84);
    }
}

int check_final_square(char **tab)
{
    if (check_last(tab) == 84)
        return (84);
    if (check_last_two(tab) == 84)
        return (84);
    if (vertical_positions(tab) == 84)
        return (84);
    if (check_lenght(tab) == 84)
        return (84);
}