/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "mysh.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    while (*str)
        my_putchar(*str++);
}

void print_tab(char **tab)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}

bool is_alpha(char c)
{
    if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z') &&
        !(c >= '0' && c <= '9')
    && !(c == '/') && !(c == '-') && !(c == '.') && !(c == '_'))
        return (false);
    return (true);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
