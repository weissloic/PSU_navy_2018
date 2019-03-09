/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** game managment
*/
#include "include/my.h"

int get_position(navy_t *navy)
{
    char *s = NULL;
    char *res;

    my_printf("attack: ");
    s = get_next_line(0);
    if (s == NULL) {
        return (84);
    }
    s = find_error(navy, s);
    print_result(navy, s);
}

int print_game_boards(navy_t *navy)
{
    my_printf("\n");
    my_printf("my positions:\n");
    for (int y = 0; y < 10; y++) {
        my_printf("%s\n", navy->create_map[y]);
    }
    my_printf("\n");
    my_printf("ennemy's positions:\n");
    for (int y = 0; y < 10; y++) {
        my_printf("%s\n", navy->create_empty_map[y]);
    }
    my_printf("\n");
    find_win(navy);
    navy->turn++;
}

int attack_turn(navy_t *navy)
{
    print_game_boards(navy);
    if (get_position(navy) == 84) {
        return (84);
    }
}

int check_shot(navy_t *navy, char *shot)
{
    int check = 0;
    int x = 0;
    int y = 0;
    int count;
    char *res = malloc(sizeof(char) * 10);
    char contains_letter[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int contains_number[] = {2, 4, 6, 8, 10, 12, 14, 16};

    for (int i = 0; contains_letter[i] != '\0'; i++) {
        if (shot[0] == contains_letter[i]) {
            check = i;
        }
    }
    y = contains_number[check];
    x = my_getarraynbr(shot, 1);
    if (navy->create_map[x + 1][y] != '.') {
        navy->create_empty_map[x + 1][y] = 'o';
        count = 0;
    } else if (navy->create_map[x + 1][y] == '.') {
        navy->create_empty_map[x + 1][y] = 'x';
        count = 1;
    }
    return (count);
}

void print_result(navy_t *navy, char *shot)
{
    if (check_shot(navy, shot) == 0) {
        my_printf("%s: hit\n\n", shot);
        my_printf("waiting for enemy's attack...\n");
        my_printf("A1: missed\n");
    } else {
        my_printf("%s: missed\n\n", shot);
        my_printf("waiting for enemy's attack...\n");
        my_printf("D1: hit\n");
        
    }
}