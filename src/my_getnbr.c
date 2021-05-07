/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** my_getnbr
*/

int calculate_sign(int sign)
{
    if (sign % 2 != 0)
        return (-1);
    return (1);
}

int my_getnbr(char const *str)
{
    long i = 0;
    long result = 0;
    long sign = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign++;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + str[i] - '0';
        i++;
    }
    result = result * calculate_sign(sign);
    if (result < -2147483648 || result > 2147483647)
        return (0);
    return (result);
}
