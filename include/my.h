/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my h
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/System/InputStream.h>
#include <stddef.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Config.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window.h>
#include <unistd.h>

#ifndef MY_H_
#define MY_H_

typedef struct button {
    sfRectangleShape *rect;
    sfRectangleShape *win;
    sfRectangleShape *lose;
    sfRenderWindow* window;
    sfEvent event;
    sfSprite *backone;
    int count;
    sfSprite *backtwo;
} button_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_in_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void init_button(button_t *button, sfVector2f position, sfVector2f size);
void print_hello(void);
int button_is_clicked(button_t *button, sfVector2i click_position);
int create_backone(button_t *button);
int create_backtwo(button_t *button);
int close_window(button_t *button);
int next_scene(button_t *button);
#endif