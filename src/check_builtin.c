/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** check_builtin
*/

#include "mysh.h"

int check_builtin(char **command, object_t *object)
{
    int i = 0;

    if (my_strcmp("cd", command[0]) == 0) {
        if (!command[1] || my_strcmp("~", command[1]) == 0)
            chdir(find_in_2d_tab(object->env, "HOME"));
        else
            my_cd(command[1]);
        return (0);
    }
    if (my_strcmp("exit", command[0]) == 0) {
        if (command[1])
            i = my_getnbr(command[1]);
        exit(i);
    }
    if (my_strcmp("env", command[0]) == 0) {
        print_tab(object->env);
        return (0);
    }
    return (check_builtin_2(command, object));
}

int check_builtin_2(char **command, object_t *object)
{
    if (my_strcmp("setenv", command[0]) == 0) {
        if (!command[1])
            print_tab(object->env);
        else if (handle_setenv_errors(command) != 0)
            return (0);
        else
            object->env = my_setenv(command, object);
        return (0);
    }
    if (my_strcmp("unsetenv", command[0]) == 0) {
        if (!command[1]) {
            my_putstr("unsetenv: Too few arguments.\n");
            return (0);
        } else {
            object->env = my_unsetenv(command, object);
        return (0);
        }
    }
    return (84);
}
