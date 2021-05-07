/*
** EPITECH PROJECT, 2020
** mysh
** File description:
** mysh
*/

#ifndef MYSH_H_
#define MYSH_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct object
{
    char **env;
} object_t;

// path.c
char *check_path_access(char **path, char **command, object_t *object);
char **get_splitted_path(char **env);
char **split_path(char *str);

//init_object
object_t *init_object(char **env);

//my_cd.c
void my_cd(char *dir);

// run_shell.c
int run_shell(object_t *object, size_t size);
void execute_command(char **command, object_t *object);

//check_builtin.c
int check_builtin(char **command, object_t *object);
int check_builtin_2(char **command, object_t *object);

//my_setenv
char **my_setenv(char **command, object_t *object);
char **update_env(object_t *object, char *name, char *value);


//my_unsetenv
char **my_unsetenv(char **command, object_t *object);
int find_line(char *str, object_t *object);
char **delete_line(int line, object_t *object);

//error.c
void handle_errors(int child_pid);
void handle_wifexited(int status);
int handle_setenv_errors(char **command);
void print_cd_error(char *dir, int status);

//my_str_to_word_array.c
char **my_str_to_word_array(char *str);
char **cut_string(char **tab, char *str, int i);
int count_words(char *str);

// utils.c
bool is_alpha(char c);
void my_putchar(char c);
void my_putstr(char *str);
void print_tab(char **tab);
int my_strlen(char const *str);

//utils2.c
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
char *find_in_2d_tab(char **tab, char *name);
char *copy_str_from_tab(char *tab);

//utils3.c
int count_args(char **command);
bool is_command_valid(char *command);
bool my_str_isalpha(char const *str);
bool is_char_letter(char c);
bool is_char_num(char c);

//utils4.c
size_t get_binary_size(const char *filename);
bool is_directory(const char *path, char *command);
void print_command_not_found(char *command);

// my_getnbr.c
int my_getnbr(char const *str);
int calculate_sign(int sign);

#endif
