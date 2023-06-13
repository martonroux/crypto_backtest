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

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    if (argc < 2)
        print_exit("Missing file name\n");
    csv_t **csv = open_csv(argv[1]);
    list_t *indics = ll_initialize();

    ll_add_first(indics, create_rsi(csv, 14));
}
