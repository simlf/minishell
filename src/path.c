/*
** EPITECH PROJECT, 2021
** path
** File description:
** path
*/

#include "mysh.h"

char *check_path_access(char **path, char **command, object_t *object)
{
    char *str;

    if (check_builtin(command, object) != 84)
        return (NULL);
    for (int i = 0; path[i]; i++) {
        str = malloc(sizeof(char) * my_strlen(path[i]) + my_strlen(command[0]));
        str = my_strcat(path[i], "/");
        str = my_strcat(str, command[0]);
        if (access(str, F_OK | X_OK) == 0)
            return (str);
    }
    str = my_strcat(find_in_2d_tab(object->env, "PWD"), "/");
    str = my_strcat(str, command[0]);
    if ((access(str, F_OK | X_OK) == 0)) {
        if (is_directory(str, command[0]) || get_binary_size(str) != 4096)
            return (NULL);
        return (str);
    }
    print_command_not_found(command[0]);
    return (NULL);
}

char **get_splitted_path(char **env)
{
    char *path = find_in_2d_tab(env, "PATH");

    return (split_path(path));
}

char **split_path(char *str)
{
    char **tab = malloc(sizeof(char) * my_strlen(str) * 2);
    int i = 0;
    int j = 0;
    int k = 0;

    tab[0] = malloc(sizeof(char) * my_strlen(str));
    while (str[k] != '\0') {
        if (str[k] == ':') {
            k++;
            j++;
            tab[j] = malloc(sizeof(char) * my_strlen(str));
            i = 0;
        }
        tab[j][i] = str[k];
        i++;
        k++;
    }
    return (tab);
}
