/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** attack
*/
#include "include/my.h"

char *find_error(navy_t *navy, char *s)
{
    if (s[0] != 65 && s[0] != 66 && s[0] != 67 && s[0] != 68 && s[0] != 
    69 && s[0] != 70 && s[0] != 71 && s[0] != 72) {
        s = wrong_position(navy, s);
    }
    if (s[1] != 49 && s[1] != 50 && s[1] != 51 && s[1] != 52 && s[1] != 
    53 && s[1] != 54 && s[1] != 55 && s[1] != 56) { 
        s = wrong_position(navy, s);
    }
    if (my_strlen(s) != 2) {
        s = wrong_position(navy, s);
    }
    return (s);
}

int find_win(navy_t *navy)
{
    int nbr = 0;

    for (int i = 0; i != 10; i++) {
        for (int j = 2; navy->create_map[i][j] != '\0'; j++) {
            if (navy->create_map[i][j] >= '0' && navy->create_map[i][j] <= '9') {
                nbr++;
            }
        }
    }
    if (nbr == 0) {
        my_printf("I lost");
        return (0);
    }
    return (1);
}