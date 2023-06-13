/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** launch_backtest.c
*/

#include "csv.h"
#include "list.h"
#include "backtest.h"
#include "strategy.h"

int act_strategy = 0;

void launch_strategies(klines_t **klines, list_t *indics, list_t *strategies, list_t *positions)
{
    strategy_t *strategy;

    for (node_t *node = strategies->first; node; node = node->next) {
        strategy = node->data;
        act_strategy = strategy->id;
        printf("Strategy: %s, id: %d, real id: %d\n", strategy->name, act_strategy, strategy->id);
        strategy->strat_func((klines_t **)klines, indics);
    }
}

void launch_backtest(klines_t **klines, list_t *indics, list_t *strategies)
{
    int size = klines[0]->size;
    list_t *positions = ll_initialize();

    for (int i = 1; i < size; i++) {
        replace_sizes(klines, indics, i);
        launch_strategies(klines, indics, strategies, positions);
    }
}
