/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "mysh.h"

char **my_str_to_word_array(char *str)
{
    char **tab = malloc(sizeof(*tab) * ((count_words(str) + 1)));
    int i = 0;

    if (tab == NULL)
        exit(84);
    while (str[i] == '\t' || str[i] == ' ')
        i++;
    tab = cut_string(tab, str, i);
    return (tab);
}

int count_words(char *str)
{
    int nb = 0;

    while (*str == ' ' || *str == '\t')
        str++;
    while (*str) {
        nb++;
        while (*str && *str != ' ' && *str != '\t')
            str++;
        if (*str == ' ' || *str == '\t')
            str++;
    }
    return (nb);
}

char **cut_string(char **tab, char *str, int i)
{
    int j = 0;
    int k = 0;

    while (str[i]) {
        tab[j] = malloc(sizeof(**tab) * (my_strlen(str) + 1));
        if (tab[j] == NULL)
            exit(84);
        k = 0;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            tab[j][k++] = str[i++];
        tab[j++][k] = '\0';
        while (str[i] == ' ' || str[i] == '\t')
            i++;
    }
    tab[j] = NULL;
    return (tab);
}

