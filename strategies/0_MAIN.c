/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** 0_MAIN.c
*/

#include "list.h"
#include "strategy.h"
#include "my.h"

void check_strategies(list_t *strategies)
{
    strategy_t *strategy = NULL;

    for (node_t *nde = strategies->first; nde; nde = nde->next) {
        strategy = nde->data;
        if (strategy->name == NULL)
            print_exit("Strategy name undefined\n");
        if (strategy->ratio == 0.0)
            print_exit("Warning: Strategy %s has 0.0 ratio\n", strategy->name);
        if (strategy->strat_func == NULL)
            print_exit("Strategy %s is missing function declaration\n", strategy->name);
        if (strategy->timeframe == 0)
            print_exit("Strategy %s is missing timeframe declaration\n", strategy->name);
    }
}

list_t *init_strategies(void)
{
    list_t *list = ll_initialize();

    ll_add_first(list, init_strategy_1());
    ll_add_first(list, init_strategy_2());
    check_strategies(list);
    create_random_ids(list);
    return list;
}
