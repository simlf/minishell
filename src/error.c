/*
** EPITECH PROJECT, 2021
** error
** File description:
** error
*/

#include "mysh.h"

void handle_errors(int status)
{
    if (WIFSIGNALED(status) == 1) {
        if (WTERMSIG(status) == 11 || WTERMSIG(status) == 139) {
            if (!WCOREDUMP(status)) {
                my_putstr("Segmentation fault\n");
            } else if (WCOREDUMP(status)) {
                my_putstr("Segmentation fault (core dumped)\n");
            }
        }
        if (WTERMSIG(status) == 8) {
            if (!WCOREDUMP(status)) {
                my_putstr("Floating exception\n");
            } else if (WCOREDUMP(status)) {
                my_putstr("Floating exception (core dumped)\n");
            }
        }
        if (WTERMSIG(status) == 7) {
            my_putstr("Bus error\n");
        }
    }
}

int handle_setenv_errors(char **command)
{
    if (count_args(command) > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (1);
    }
    if (!is_char_letter(command[1][0])) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    if (!my_str_isalpha(command[1])) {
        my_putstr("setenv: Variable name must contain alphanumeric characters");
        my_putstr(".\n");
        return (1);
    }
    return (0);
}

void print_cd_error(char *dir, int status)
{
    if (status == -1) {
        my_putstr(dir);
        my_putstr(": No such file or directory.\n");
    }
}
