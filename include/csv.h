/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** csv.h
*/

#ifndef C_BACKTEST_CSV_H
    #define C_BACKTEST_CSV_H

    #include <stdio.h>

typedef struct klines_s {
    char *name;
    int size;
    double *data;
} klines_t;

int file_size(char *file_name);
klines_t **open_csv(char *file_name);
klines_t **get_columns(char *file_name, int size);
klines_t **init_csv(char **columns, int size, int nb_tokens);
void read_csv_line(FILE *file, klines_t **csv, int line);

#endif
