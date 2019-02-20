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
    char *buffer = malloc(sizeof(char) * 47);

    if (fd == -1) {
        my_putstr("Error with open\n");
        return (84);
    }
    read(fd, buffer, 47);
    buffer[46] = '\0';
    return (buffer);
}

void find_positions(char *filepath)
{
    char **map = malloc(sizeof(char*) * 12);
    char *buffer = find_my_file(filepath);
    int line = 0;
    int cols = 0;

    for (int i = 0; i != 5; i++) {
        map[i] = malloc(sizeof(char) * 3);
    }
    for (int g = 0; g != 30; g++) {
        if (buffer[g] >= 30 && buffer[g] <= 39)
            printf("%c\n", buffer[g - 1]);
        if (buffer[g] >= 30 && buffer[g] <= 39 && buffer[g - 1] >= 41 && buffer[g - 1] <= 48) {
            cols++;
            map[line][cols - 1] = buffer[g - 1];
            map[line][cols] = buffer[g];
            line++;
            cols = 0;
            printf("ok\n");
        } else if (buffer[g] >= 30 && buffer[g] <= 39 && buffer[g - 1] == ' ') {
            map[line][cols] = buffer[g];
            line++;
            cols = 0;
        }
    }
    for (int k = 0; k != 3; k++) {
        printf("%s\n", map[k]);
    }
}

int main(void)
{
    find_positions("navy_positions.txt");
}