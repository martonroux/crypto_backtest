/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** file_size.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int file_size(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    char *linep = NULL;
    size_t linecapp = 0;
    int size = 0;

    if (file == NULL)
        print_exit("File not found\n");
    for (; (getline(&linep, &linecapp, file) != -1); size++) {
        free(linep);
        linep = NULL;
    }
    fclose(file);
    return size;
}
