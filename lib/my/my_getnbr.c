/*
** EPITECH PROJECT, 2018
** get_nbr
** File description:
** get nbr
*/

int my_getnbr(char *str)
{
    int i = 0;
    int n = 0;

    if (str[0] == '-' && str[1] != 0) {
        i++;
    }
    for (i; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            n = n + str[i] - 48;
            n = n * 10;
        }
    }
    n /= 10;
    if (str[0] == ' ') {
        return (n * -1);
    } else {
        return (n);
    }
}