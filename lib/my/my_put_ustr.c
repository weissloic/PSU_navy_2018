/*
** EPITECH PROJECT, 2018
** my_put_ustr
** File description:
** my_put_ustr
*/
#include "../../include/my.h"

int my_put_unsigned_str(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] < 127) {
            my_putchar(str[i]);
        } else if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            if (convert_tobase(str[i], "01234567") <= 9) {
                my_putstr("00");
                convert_tobase(str[i], "01234567");
            } else {
                my_putchar('0');
                convert_tobase(str[i], "01234567");
            }
        }
    }
    return (0);
}
