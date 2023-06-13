/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** replace_sizes.c
*/

#include "csv.h"
#include "list.h"
#include "klines.h"

void replace_sizes(klines_t **klines, list_t *indics, int size)
{
    node_t *node = indics->first;
    indicator_t *indicator;

    for (int i = 0; klines[i]; i++)
        klines[i]->size = size;
    while (node) {
        indicator = node->data;
        indicator->size = size;
        node = node->next;
    }
}
