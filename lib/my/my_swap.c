/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** my swap
*/

void my_swap(int *a, int *b)
{
    int test;
    test = *a;
    *a = *b;
    *b = test;
}
