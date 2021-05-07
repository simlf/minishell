/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** init_env
*/

#include "mysh.h"

object_t *init_object(char **env)
{
    object_t *object = malloc(sizeof(*env));

    if (!env)
        return (NULL);
    object->env = env;
    return (object);
}
