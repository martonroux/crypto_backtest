/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** open_csv.c
*/

#include "csv.h"
#include "my.h"

csv_t **open_csv(char *file_name)
{
    printf("Opening csv file...\n");
    int size = file_size(file_name);
    csv_t **csv = get_columns(file_name, size - 1);
    FILE *file = fopen(file_name, "r");

    if (file == NULL)
        print_exit("File not found\n");
    skip_file_line(file);
    for (int i = 0; i < size - 1; i++)
        read_csv_line(file, csv, i);
    return csv;
}
