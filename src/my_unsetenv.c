/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** my_unsetenv
*/

#include "mysh.h"

char **my_unsetenv(char **command, object_t *object)
{
    int i = find_line(command[1], object);

    if (i == -1)
        return (object->env);
    return (delete_line(i, object));
}

int find_line(char *str, object_t *object)
{
    int i = 0;

    for (i = 0; object->env[i]; i++) {
        if (object->env[i][0] == str[0] && object->env[i][1] == str[1] && \
            object->env[i][2] == str[2])
            return (i);
    }
    return (-1);
}

char **delete_line(int line, object_t * object)
{
    int i = 0;
    int j = 0;
    int len;
    char **updated_env;

    for (len = 0; object->env[len]; len++);
    updated_env = malloc(sizeof(char *) * len + 5);
    if (!updated_env)
        return (NULL);
    while (i != len) {
        if (i != line) {
            updated_env[j] = my_strdup(object->env[i]);
            j++;
        }
        i++;
    }
    updated_env[len] = '\0';
    return (updated_env);
}




