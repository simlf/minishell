/*
** EPITECH PROJECT, 2021
** my_cd
** File description:
** my_cd
*/

#include "mysh.h"

void my_cd(char *dir)
{
    int status = 0;

    status = chdir(dir);
    chdir(dir);
    print_cd_error(dir, status);
}
