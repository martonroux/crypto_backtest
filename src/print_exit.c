/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** print_exit.c
*/

#include <stdio.h>
#include <stdlib.h>

void print_exit(char *txt)
{
    fprintf(stderr, "%s", txt);
    exit(EXIT_FAILURE);
}
