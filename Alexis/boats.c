/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** place my boats
*/
#include "include/my.h"

int put_first_square(navy_t *navy, int x, int y, char boat)
{
    navy->create_map[x + 1][y] = boat;
}

int put_second_square(navy_t *navy, int x, int y, char boat)
{
    navy->create_map[x + 1][y] = boat;
}

int first_blocks(navy_t *navy, char boat, int nbr)
{
    put_first_square(navy, navy->value_one[1][nbr], navy->value_one[0][nbr], boat);
    put_second_square(navy, navy->value_two[1][nbr], navy->value_two[0][nbr], boat);
}

int check_sens(navy_t *navy, int nbr)
{
    if (navy->value_one[0][nbr] != navy->value_two[0][nbr]) {
        navy->horizontal++;
    } else {
        navy->vertical++;
    }
}

int first_boat(navy_t *navy, char boat, int nbr)
{
    check_sens(navy, nbr);
    if (navy->horizontal == 1) {
        for (int i = navy->value_one[0][nbr] / 2; i != navy->value_two[0][nbr] / 2; i++) {
            navy->create_map[navy->value_one[1][nbr] + 1][i * 2] = boat;
            printf("%d\n", navy->value_one[0][nbr]);
        }
        navy->horizontal = 0;
    } else if (navy->vertical == 1) {
        for (int i = navy->value_one[1][nbr]; i != navy->value_two[1][nbr]; i++) {
            navy->create_map[i + 1][navy->value_one[0][nbr]] = boat;
        }
        navy->vertical = 0;
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