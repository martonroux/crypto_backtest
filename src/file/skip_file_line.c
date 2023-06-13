/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** skip_file_line.c
*/

#include <stdio.h>

void skip_file_line(FILE *file)
{
    char *linep = NULL;
    size_t linecapp = 0;

    getline(&linep, &linecapp, file);
}
