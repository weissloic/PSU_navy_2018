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
    fd = open("navy_positions.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 32);

    if (fd == -1) {
        my_putstr("Error with open\n");
        return (84);
    }
    read(fd, buffer, 31);
    buffer[32] = '\0';
    return (buffer);
}

char **find_positions(char *filepath)
{
    char **map = malloc(sizeof(char*) * 12);
    char *buffer = find_my_file(filepath);
    int line = 0;
    int cols = 0;

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

int main(void)
{
    navy_t *navy = malloc(sizeof(navy_t));
    char **map;

    print_map(navy);
    map = find_positions("navy_positions.txt");
    put_my_boats(navy, map);
    for (int y = 0; y < 10; y++)
        printf("%s\n", navy->create_map[y]);
}