/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** read_csv_line.c
*/

#include "csv.h"
#include "my.h"

void read_csv_line(FILE *file, csv_t **csv, int line)
{
    size_t linecapp = 0;
    char *linep = NULL;
    char **splitted = NULL;
    int num_tokens;

    if (file == NULL)
        print_exit("File not found\n");
    if (getline(&linep, &linecapp, file) != -1) {
        num_tokens = 0;
        splitted = split(linep, ';', &num_tokens);
        for (int i = 0; i < num_tokens; i++)
            csv[i]->data[line] = atof(splitted[i]);
    }
}
