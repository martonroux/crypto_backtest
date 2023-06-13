/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** get_columns.c
*/

#include "csv.h"
#include "my.h"

csv_t **get_columns(char *file_name, int size)
{
    FILE *file = fopen(file_name, "r");
    char *linep = NULL;
    char **splitted;
    size_t linecapp = 0;
    int nb_tokens = 0;

    if (file == NULL)
        print_exit("File not found\n");
    getline(&linep, &linecapp, file);
    remove_newline(linep);
    splitted = split(linep, ';', &nb_tokens);
    fclose(file);
    return init_csv(splitted, size, nb_tokens);
}
