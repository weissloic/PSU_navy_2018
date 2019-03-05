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
        my_putstr("Error with open\n");
        return (84);
    }
    read(fd, buffer, 31);
    buffer[32] = '\0';
    return (buffer);
}

void handler(int signal, siginfo_t *info, void *context)
{
    if (signal == SIGUSR1) {
        my_printf("TESTA");
    }
    if (signal == SIGUSR2) {
        game->connect_or_not++;
        game->counter++;
        //if (game->connect_or_not == 1)
            //my_printf("GG connected");
    }
    //game->counter = 0;
    game->pid_glob = info->si_pid;
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
    game = malloc(sizeof(global_t));
    char **map;
    navy->turn = 0;
    navy->ac = ac;
    int producer_pid = 0;
    game->counter = 0;

    struct sigaction act;
    
    game->pid_glob = 0;
    game->counter = 0;
    game->connect_or_not = 0;
    act.sa_sigaction = &handler;

    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);

    if (ac == 3) {
        producer_pid = my_getnbr(av[1]);
        kill(producer_pid, SIGUSR2);
        //game->counter++;
        print_map(navy);
        print_empty(navy);
        map = find_positions(av[2], navy);
        if (find_positions(av[2], navy) == 84) {
            return (84);
        }
        put_my_boats(navy, map);

        while (1) {
            if (attack_turn(navy) == 84) {
                return (84);
            }
        }
        return(0);
    }
    else {
        my_printf("pid = %d\n", getpid());
        my_printf("Waiting for ennemy connections\n");

        while (1) {
            if (game->counter == 1) {
            print_map(navy);
            print_empty(navy);
            map = find_positions(av[1], navy);
            if (find_positions(av[1], navy) == 84) {
                return (84);
            }
            put_my_boats(navy, map);

            while (1) {
                if (attack_turn(navy) == 84) {
                    return (84);
                }
            }
            return(0);
        }
    }
}
}