/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** get_start.c
*/

#include "csv.h"
#include "klines.h"
#include "my.h"

double *get_start(csv_t **klines)
{
    for (int i = 0; klines[i]; i++) {
        if (strcmp(klines[i]->name, START_NAME) == 0) {
            return klines[i]->data;
        }
    }
    print_exit("Did not find START values in KLINES\n");
    return NULL;
}
