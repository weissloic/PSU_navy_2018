/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

global_t *game;

void receiver_signal(struct sigaction act)
{
    game->pid_glob = 0;
    game->counter = 0;
    game->connect_or_not = 0;
    act.sa_sigaction = &handler;

    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
}

int player_two(char **map, struct sigaction act, char **av, navy_t *navy)
{
        print_map(navy);
        print_empty(navy);
        map = find_positions(av[2], navy);
        if (find_positions(av[2], navy) == 84)
            return (84);
        kill(my_getnbr(av[1]), SIGUSR2);
        my_printf("my_pid: %d\n", getpid());
        my_printf("successfully connected\n");
        put_my_boats(navy, map);
        while (1) {
            if (attack_turn(navy) == 84)
                return (84);
        }
}

int player_one(char **map, char **av, navy_t *navy)
{
    print_map(navy);
    print_empty(navy);
    map = find_positions(av[1], navy);
    if (find_positions(av[1], navy) == 84)
        return (84);
    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    while (1) {
        if (game->counter == 1) {
            my_printf("ennemy connected\n");
            put_my_boats(navy, map);
            if (attack_turn(navy) == 84)
                return (84);
        }
    }
}

void my_norm(struct sigaction act, int ac, navy_t *navy)
{
    navy->turn = 0;
    navy->ac = ac;
    game->counter = 0;
    receiver_signal(act);
}

int main(int ac, char **av)
{
    navy_t *navy = malloc(sizeof(navy_t));
    game = malloc(sizeof(global_t));
    struct sigaction act;
    char **map;
    my_norm(act, ac, navy);

    if (ac == 3) {
        player_two(map, act, av, navy);
        if (player_two(map, act, av, navy) == 84)
            return (84);
        return (0);
    } else if (ac == 2) {
            player_one(map, av, navy);
            if (player_one(map, av, navy) == 84)
                return (84);
            return (0);
        }
    else
        return (84);
}