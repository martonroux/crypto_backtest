/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** my.h
*/

#ifndef C_BACKTEST_MY_H
    #define C_BACKTEST_MY_H

    #define ABS(x) ((x) < 0 ? (-x) : (x))

    #include <math.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <string.h>

void print_exit(const char *str, ...);
char **split(const char* str, char delim, int* num_tokens);
void skip_file_line(FILE *file);
void remove_newline(char *str);
double calc_average(const double *numbers, int size);
double round_to(double nb, int precision);

#endif
