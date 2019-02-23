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

int check_sens(navy_t *navy, int i, char **tab, int x1, int y1, int x2, int y2)
{
    if (y1 != y2) {
        navy->horizontal++;
    } else {
        navy->vertical++;
    }
}

int first_boat(navy_t *navy, int x1, int y1, int x2, int y2, char boat, char **tab)
{
    check_sens(navy, 0, tab, x1, y1, x1, y2);
    if (navy->horizontal == 1) {
        for (int i = y1; i != y2; i++) {
            navy->create_map[x1 + 1][i * 2] = boat;
        }
        navy->horizontal = 0;
    } else if (navy->vertical == 1) {
        for (int i = x1; i != x2; i++) {
            navy->create_map[i + 1][y1 * 2] = boat;
            printf("%d\n", i + 1);
            printf("%d\n", y1 + 2);
        }
        navy->vertical = 0;
    }
}

int second_boat(navy_t *navy, int x1, int x2, int y1, int y2, char boat, char **tab)
{
    check_sens(navy, 1, tab, x1, y1, x1, y2);
    if (navy->horizontal == 1) {
        for (int i = y1; i != y2; i++) {
            navy->create_map[x1 + 1][i * 2] = boat;
        }
        navy->horizontal = 0;
    } else if (navy->vertical == 1) {
        for (int i = x1; i != x2; i++) {
            navy->create_map[i + 1][y1 + 2] = boat;
        }
        navy->vertical = 0;
    }
}

int third_boat(navy_t *navy, int x1, int x2, int y1, int y2, char boat, char **tab)
{
    check_sens(navy, 2, tab, x1, y1, x1, y2);
    if (navy->horizontal == 1) {
        for (int i = y1; i != y2; i++) {
            navy->create_map[x1 + 1][i * 2] = boat;
        }
        navy->horizontal = 0;
    } else if (navy->vertical == 1) {
        for (int i = x1; i != x2; i++) {
            navy->create_map[i + 1][y1 + 2] = boat;
        }
        navy->vertical = 0;
    }
}

int fourth_boat(navy_t *navy, int x1, int x2, int y1, int y2, char boat, char **tab)
{
    check_sens(navy, 3, tab, x1, y1, x1, y2);
    if (navy->horizontal == 1) {
        for (int i = y1; i != y2; i++) {
            navy->create_map[x1 + 1][i * 2] = boat;
        }
        navy->horizontal = 0;
    } else if (navy->vertical == 1) {
        for (int i = x1; i != x2; i++) {
            navy->create_map[i + 1][y1 + 2] = boat;
        }
        navy->vertical = 0;
    }
}

int put_my_boats(navy_t *navy, char **tab)
{
    first_blocks(navy, 2, 3, 2, 4, '2', tab);
    first_boat(navy, 2, 3, 2, 4, '2', tab);
    first_blocks(navy, 2, 2, 4, 2, '3', tab);
    first_boat(navy, 2, 2, 4, 2, '3', tab);
    first_blocks(navy, 1, 7, 4, 7, '4', tab);
    first_boat(navy, 1, 7, 4, 7, '4', tab);
    first_blocks(navy, 6, 3, 6, 7, '5', tab);
    first_boat(navy, 6, 3, 6, 7, '5', tab);
}