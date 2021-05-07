/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "mysh.h"

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;

    int i;
    object_t *object = init_object(env);
    size_t size = 1024;

    i = run_shell(object, size);
    if (i == 0)
        free(object);
    return (0);
}
