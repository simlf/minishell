/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** utils4
*/

#include "mysh.h"

size_t get_binary_size(const char *filename)
{
    struct stat st;

    if (stat(filename, &st) != 0)
        return (0);
    return (st.st_blksize);
}

bool is_directory(const char *path, char *command)
{
    struct stat statbuf;

    if (stat(path, &statbuf) != 0)
        return (false);
    if (S_ISDIR(statbuf.st_mode))
    {
        my_putstr(command);
        my_putstr(": Permission denied.\n");
        return (true);
    }
    my_putstr("False\n");
    return (false);
}

void print_command_not_found(char *command)
{
    my_putstr(command);
    my_putstr(": Command not found.\n");
}
