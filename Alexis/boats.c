/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** place my boats
*/
#include "include/my.h"

int put_first_square(navy_t *navy, int x, int y, char boat)
{
    navy->create_map[x + 1][y * 2] = boat;
}

int put_second_square(navy_t *navy, int x, int y, char boat)
{
    navy->create_map[x + 1][y * 2] = boat;
}

int first_blocks(navy_t *navy, int x1, int y1, int x2, int y2, char boat, char **tab)
{
    put_first_square(navy, x1, y1, boat);
    put_second_square(navy, x2, y2, boat);
}

int check_sens(navy_t *navy, int i, char **tab)
{
    if (tab[i][2] == tab[i][5]) {
        navy->horizontal++;
    } else {
        navy->vertical++;
    }
}

int first_boat(navy_t *navy, int x1, int y1, int x2, int y2, char boat, char **tab)
{
    check_sens(navy, 0, tab);
    if (navy->horizontal == 1) {
        for (int i = y1; i != y2; i++) {
            if (i % 2 != 0) {
                navy->create_map[i + 1][y1 * 2] = boat;
            }
        }
        navy->horizontal = 0;
    } else if (navy->vertical == 1) {
        for (int i = x1; i != x2; i++) {
            navy->create_map[i + 1][y1 + 2] = boat;
        }
        navy->vertical = 0;
    }
}

int second_boat(navy_t *navy, int x1, int x2, int y1, int y2, char boat, char **tab)
{
    check_sens(navy, 1, tab);
    if (navy->horizontal == 1) {
        for (int i = y1; i != y2; i++) {
            if (i % 2 == 0) {
                navy->create_map[i + 1][y1 * 2] = boat;
            }
        }
        navy->horizontal = 0;
    } else if (navy->vertical == 1) {
        for (int i = x1; i != x2; i++) {
            navy->create_map[i + 1][y1 * 2] = boat;
        }
        navy->vertical = 0;
    }
}

int third_boat(navy_t *navy, int x1, int x2, int y1, int y2, char boat, char **tab)
{
    check_sens(navy, 2, tab);
    if (navy->horizontal == 1) {
        for (int i = y1; i != y2; i++) {
            if (i % 2 == 0) {
                navy->create_map[i + 1][y1 * 2] = boat;
            }
        }
        navy->horizontal = 0;
    } else if (navy->vertical == 1) {
        for (int i = x1; i != x2; i++) {
            navy->create_map[i + 1][y1 * 2] = boat;
        }
        navy->vertical = 0;
    }
}

int fourth_boat(navy_t *navy, int x1, int x2, int y1, int y2, char boat, char **tab)
{
    check_sens(navy, 3, tab);
    if (navy->horizontal == 1) {
        for (int i = y1; i != y2; i++) {
            if (i % 2 == 0) {
                navy->create_map[i + 1][y1 * 2] = boat;
            }
        }
        navy->horizontal = 0;
    } else if (navy->vertical == 1) {
        for (int i = x1; i != x2; i++) {
            navy->create_map[i + 1][y1 * 2] = boat;
        }
        navy->vertical = 0;
    }
}

int put_my_boats(navy_t *navy, char **tab)
{
    //first_blocks(navy, 2, 3, 2, 2, '2', tab);
    //first_boat(navy, 2, 3, 2, 2, '2', tab);
    first_blocks(navy, 2, 3, 4, 3, '3', tab);
    first_boat(navy, 2, 3, 4, 3, '3', tab);
}