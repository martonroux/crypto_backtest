/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** main.c
*/

#include "csv.h"
#include "my.h"
#include "klines.h"
#include "list.h"
#include "strategy.h"
#include "backtest.h"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    if (argc < 2)
        print_exit("Missing file name\n");
    klines_t **csv = open_csv(argv[1]);
    list_t *indics = ll_initialize();
    list_t *strategies = init_strategies();

    ll_add_first(indics, create_rsi(csv, 14));
    launch_backtest(csv, indics, strategies);
}
