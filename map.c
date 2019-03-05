/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** creation of the map
*/
#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *find_my_file(char *filepath)
{
    int fd;
    fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 100);

    if (fd == -1) {
        my_putstr("Error with open\n");
        return (84);
    }
    read(fd, buffer, 31);
    buffer[32] = '\0';
    return (buffer);
}

char **find_positions(char *filepath, navy_t *navy)
{
    char **map = malloc(sizeof(char*) * 12);
    char *buffer = find_my_file(filepath);
    int line = 0;
    int cols = 0;
    char **position = malloc(sizeof(char *) * 10);
    navy->value_one = malloc(sizeof(int *) * 4);
    navy->value_two = malloc(sizeof(int *) * 4);

    for (int i = 0; i != 3; i++) {
        navy->value_one[i] = malloc(sizeof(int) * 4);
    }
    for (int i = 0; i != 3; i++) {
        navy->value_two[i] = malloc(sizeof(int) * 4);
    }
    for (int i = 0; i != 5; i++) {
        position[i] = malloc(sizeof(char) * 3);
    }
    for (int i = 0; i != 5; i++) {
        map[i] = malloc(sizeof(char) * 3);
    }
    for (int i = 0; i != my_strlen(buffer); i++) {
        if (buffer[i] == '\n') {
            line++;
            cols = 0;
        } else {
            map[line][cols] = buffer[i];
            cols++;
        }
    }
    if (check_errors(map) == 84) {
        return (84);
    }
    position = cpy_array(position, map);

    char contains_letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int contains_number[] = {2, 4, 6, 8, 10, 12, 14, 16};
    
    cpy_first_letter(contains_number, contains_letter, navy, position);
    cpy_second_letter(contains_number, contains_letter, navy, position);
    return (map);
}

int my_strbackslashlen(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        count++;
    }
    return (count);
}

int main(int ac, char **av)
{
    navy_t *navy = malloc(sizeof(navy_t));
    char **map;
    navy->turn = 0;
    navy->ac = ac;

    print_map(navy);
    print_empty(navy);
    map = find_positions(av[1], navy);
    put_my_boats(navy, map);

    while (1) {
        attack_turn(navy) == 0;
    }
    return(0);
}