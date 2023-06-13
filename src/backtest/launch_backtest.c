/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** launch_backtest.c
*/

#include "csv.h"
#include "list.h"
#include "backtest.h"

int act_strategy = 0;

void launch_backtest(csv_t **klines, list_t *indics)
{
    int size = klines[0]->size;

    for (int i = 1; i < size; i++) {
        replace_sizes(klines, indics, i);

    }
}
