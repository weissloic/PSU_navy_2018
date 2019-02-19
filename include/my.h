/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my h
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <string.h>
#include <errno.h>

#ifndef MY_H_
#define MY_H_

typedef struct mysh {
    char **path;
    int e;
    char **tmp;
    char *command;
    char *file;
    char *pwd;
    int line;
    char *home;
    int c;
    char *buffer;
    char **test;
    int count;
    int pathline;
    int letter;
    int i;
} mysh_t;

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
int my_printf(char *s, ...);
void display_int(va_list ap);
void display_string(va_list ap);
void display_char(va_list ap);
void display_pointer(va_list ap);
int convert_tobase(int nbr, char* base);
void convert_to_bin(va_list ap);
void convert_to_octo(va_list ap);
void convert_to_hexa(va_list ap);
void convert_to_mhexa(va_list ap);
void display_unsigned(va_list ap);
long my_put_long_nbr(long nb);
unsigned int my_put_unsigned_nbr(unsigned int nb);
int my_put_unsigned_str(char const *str);
void display_unprintable(va_list ap);
void display_percentage();
int find_path(char **new_envp, mysh_t *m);
int create_path_array(char **new_envp, mysh_t *m);
int create_tmp_array(char **new_envp, mysh_t *m);
int get_command(mysh_t *m, char **new_envp);
int concatenate_command(mysh_t *m);
int find_flag_one(mysh_t *m, char **new_envp);
int find_flag_two(mysh_t *m, char **new_envp);
int get_file(mysh_t *m, char *buffer);
int execute_command(mysh_t *m, char *buffer, char **new_envp);
int find_flag_three(mysh_t *m, char *buffer, char **new_envp);
int find_home(mysh_t *m, char **new_envp);
int retrieve_home(mysh_t *m, char **new_envp);
void stock_args(mysh_t *m, char *buffer);
int count_space(char *str);
int count_path(char *str);
int count_command(mysh_t *m, char *buffer);
int count_file(mysh_t *m, char *buffer);
char *delete_tabs(char *str);
int env_flags(mysh_t *m, char *buffer);
static void (*ptr1[9])(va_list) = {
    &display_int,
    &display_int,
    &convert_to_octo,
    &convert_to_hexa,
    &convert_to_mhexa,
    &display_char,
    &display_string,
    &convert_to_bin,
    &display_percentage,
};
#endif
