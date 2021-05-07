/*
** EPITECH PROJECT, 2021
** utils2
** File description:
** utils2
*/

#include "mysh.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j]) {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (84);
    if (s1[i] == '\0')
        return (s1[i] - s2[i]) ;
    while (s1[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]) ;
        i++;
    }
    return (0) ;
}

char *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * len + 1);

    while (i <= len) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *find_in_2d_tab(char **tab, char *name)
{
    char *str;
    int i = 0;

    while (tab[i]) {
        if (tab[i][0] == name[0] && tab[i][1] == name[1] &&
            tab[i][2] == name[2]) {
            str = copy_str_from_tab(tab[i]);
            return (str);
        }
        i++;
    }
    return (0);
}

char *copy_str_from_tab(char *tab)
{
    char *str = malloc(sizeof(char) * my_strlen(tab) + 1);
    int i = 0;
    int k = 0;

    if (str == NULL)
        return (0);
    while (tab[i] != '=')
        i++;
    i++;
    while (tab[i])
    {
        str[k] = tab[i];
        i++;
        k++;
    }
    str[k] = '\0';
    return (str);
}
