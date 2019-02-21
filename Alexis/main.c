/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "include/my.h"
#include <signal.h>

/*int process_info(void)
{
    pid_t thisPID = getpid();
    pid_t parentPID = getppid();
    pid_t groupID = getpgid(thisPID);
    printf("PID: %d\n", thisPID);
    printf("PPID: %d\n", parentPID);
    printf("GID: %d\n", parentPID);
}

int kill_it(int ac, char **av)
{
    int kill_process = my_getnbr(av[1]);
    printf("%d", kill_process);
}

int catch_signal(int signal, siginfo_t *info, void *x)
{
    if (signal == SIGKILL)
        printf("unable");
    else
        printf("%s siganl received %d\n", strsignal(signal), info->si_pid);
}

int exercisethree(int ac, char **av)
{
    pid_t thisPID = getpid();
    printf("[1] %d\n", thisPID);
    struct sigaction *new_action;
    new_action = malloc(sizeof(struct sigaction));
    new_action->sa_sigaction = catch_signal;


    sigaction (my_getnbr(av[1]), new_action, NULL);
    sigaction (my_getnbr(av[2]), new_action, NULL);
    //sigaction (SIGQUIT, snew_action, NULL);
}

int main(int ac, char **av)
{
    //process_info();
    //kill_it(ac, av);

    while (1)
        exercisethree(ac, av);




    return 0;
}*/

void fill_map_one(navy_t *navy)
{
    navy->create_map[0][0] = ' ';
    navy->create_map[0][1] = '|';
    navy->create_map[0][2] = 'A';
    navy->create_map[0][3] = ' ';
    navy->create_map[0][4] = 'B';
    navy->create_map[0][5] = ' ';
    navy->create_map[0][6] = 'C';
    navy->create_map[0][7] = ' ';
    navy->create_map[0][8] = 'D';
    navy->create_map[0][9] = ' ';
    navy->create_map[0][10] = 'E';
    navy->create_map[0][11] = ' ';
    navy->create_map[0][12] = 'F';
    navy->create_map[0][13] = ' ';
    navy->create_map[0][14] = 'G';
    navy->create_map[0][15] = ' ';
    navy->create_map[0][16] = 'H';
    navy->create_map[1][0] = '-';
    navy->create_map[1][1] = '+';
}

void fill_map_two(navy_t *navy)
{
    for (int i = 2; i != 17; i++)
        navy->create_map[1][i] = '-';
    navy->create_map[1][18] = '\n';
    navy->create_map[2][0] = '1';
    navy->create_map[3][0] = '2';
    navy->create_map[4][0] = '3';
    navy->create_map[5][0] = '4';
    navy->create_map[6][0] = '5';
    navy->create_map[7][0] = '6';
    navy->create_map[8][0] = '7';
    navy->create_map[9][0] = '8';

    for (int i = 2; i <= 9; i++)
        navy->create_map[i][1] = '|';
}

void fill_map_three(navy_t *navy)
{
    int fill_map = 2;
    for (int i = 2; fill_map != 10; i++) {
        if (i == 17) {
            fill_map++;
            i = 2;
        }
        navy->create_map[fill_map][i] = '.';
        if (i % 2 == 1)
            navy->create_map[fill_map][i] = ' ';
    }
}

void print_map(navy_t *navy)
{
    navy->create_map = malloc(sizeof(char *) * 18);

    for (int i = 0; i < 18; i++)
        navy->create_map[i] = malloc(sizeof(char) * 11);

    fill_map_one(navy);
    fill_map_two(navy);
    fill_map_three(navy);
}