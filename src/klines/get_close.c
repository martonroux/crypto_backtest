/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** get_close.c
*/

#include "csv.h"
#include "klines.h"
#include "my.h"

double *get_close(csv_t **klines)
{
    for (int i = 0; klines[i]; i++) {
        if (strcmp(klines[i]->name, CLOSE_NAME) == 0) {
            return klines[i]->data;
        }
    }
    print_exit("Did not find CLOSE values in KLINES\n");
    return NULL;
}
