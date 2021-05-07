/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** utils3
*/

#include "mysh.h"

int count_args(char **command)
{
    int i = 0;

    while (command[i])
        i++;
    return (i);
}

bool is_command_valid(char *command)
{
    int i = 0;

    while (command[i])
    {
        if (command[i] != ' ' && command[i] != '\n' && command[i] != '\t')
            return (true);
        i++;
    }
    return false;
}

bool my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (!is_char_letter(str[i]) && !is_char_num(str[i]) && \
        !(str[i] == '.') && !(str[i] == ';') && !(str[i] == '_'))
            return (false);
        i++;
    }
    return (true);
}

bool is_char_num(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

bool is_char_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (true);
    return (false);
}

