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

global_t *game;

char *find_my_file(char *filepath)
{
    int fd;
    fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 100);

    if (fd == -1) {
        return (84);
    }
    read(fd, buffer, 31);
    buffer[32] = '\0';
    return (buffer);
}

void handler(int signal, siginfo_t *info, void *context)
{
    if (signal == SIGUSR1) {
    }
    if (signal == SIGUSR2) {
        game->connect_or_not++;
        game->counter++;
    }
    game->pid_glob = info->si_pid;
}

char **map_send(char *buffer, char **map)
{
    int line = 0;
    int cols = 0;
    for (int i = 0; i != my_strlen(buffer); i++) {
        if (buffer[i] == '\n') {
            line++;
            cols = 0;
        } else {
            map[line][cols] = buffer[i];
            cols++;
        }
    }
    return (map);

}

char **find_positions(char *filepath, navy_t *navy)
{
    char **map = malloc(sizeof(char *) * 12);
    char *buffer = find_my_file(filepath);
    if (find_my_file(filepath) == 84)
        return (84);
    char **position = malloc(sizeof(char *) * 10);
    navy->value_one = malloc(sizeof(int *) * 4);
    navy->value_two = malloc(sizeof(int *) * 4);
    malloc_one(position, navy, map);
    map_send(buffer, map);
    if (check_errors(map) == 84)
        return (84);
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