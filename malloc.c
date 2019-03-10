/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"

void malloc_one(char **position, navy_t *navy, char **map)
{
    for (int i = 0; i != 3; i++)
        navy->value_one[i] = malloc(sizeof(int) * 4);
    for (int i = 0; i != 3; i++)
        navy->value_two[i] = malloc(sizeof(int) * 4);
    for (int i = 0; i != 5; i++)
        position[i] = malloc(sizeof(char) * 3);
    for (int i = 0; i != 5; i++)
        map[i] = malloc(sizeof(char) * 3);
}
