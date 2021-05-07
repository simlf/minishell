/*
** EPITECH PROJECT, 2021
** run_shell
** File description:
** run_shell
*/

#include "mysh.h"

int run_shell(object_t *object, size_t size)
{
    char *command = malloc(size);
    int len = 0;
    int status = 0;

    while (len > -1) {
        if (isatty(STDIN_FILENO))
            my_putstr("$>");
        len = getline(&command, &size, stdin);
        if (len >= 0 && is_command_valid(command)) {
            command[len - 1] = '\0';
            if (command[0] != '\0') {
                execute_command(my_str_to_word_array(command), object);
                wait(&status);
                handle_errors(status);
            }
        }
    }
    if (len == - 1)
        return (-1);
    return (0);
}

void execute_command(char **command, object_t *object)
{
    char **path;
    char *path_access;
    pid_t pid;

    path = get_splitted_path(object->env);
    path_access = check_path_access(path, command, object);
    pid = fork();
    if (pid == 0) {
        execve(path_access, command, object->env);
        exit(0);
    }
}
