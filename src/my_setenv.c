/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** my_setenv
*/

#include "mysh.h"

char **my_setenv(char **command, object_t *object)
{
    if (!command[2])
        return (update_env(object, command[1], NULL));
    if (command[2])
        return (update_env(object, command[1], command[2]));
    return (NULL);
}

char **update_env(object_t *object, char *name, char *value)
{
    int i;
    int len;
    char **updated_env;

    for (len = 0; object->env[len]; len++);
    updated_env = malloc(sizeof(char *) * len + 5);
    if (!updated_env)
        return (NULL);
    for (i = 0; i != len; i++)
        updated_env[i] = my_strdup(object->env[i]);
    updated_env[len] = my_strdup(name);
    updated_env[len] = my_strcat(updated_env[len], "=");
    if (value)
        updated_env[len] = my_strcat(updated_env[len], value);
    updated_env[len + 1] = '\0';
    return (updated_env);
}

