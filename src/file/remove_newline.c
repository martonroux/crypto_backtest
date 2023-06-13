/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** remove_newline.c
*/

#include <string.h>

void remove_newline(char *str)
{
    int len = strlen(str);

    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}
