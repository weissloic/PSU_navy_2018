/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int g = 0;

    while (dest[i] != '\0')
        i++;
    while (src[g] != '\0') {
        dest[i] = src[g];
        i++;
        g++;
    }
    dest[i] = '\0';
    return (dest);
}
