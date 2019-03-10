/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (int j = 0; s1[j] != '\0' && s2[j] != '\0'; j++) {
        if (s1[i] == s2[i]) {
            i++;
        }
    }
    return (s1[i] - s2[i]);
}