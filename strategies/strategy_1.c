/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** strategy_1.c
*/

#include <string.h>
#include "strategy.h"

position_t *strategy_1(klines_t **klines, list_t *indics)
{
    return new_position(klines, 0, 0, BUY);
}

strategy_t *init_strategy_1(void)
{
    strategy_t *strategy = malloc(sizeof(strategy_t));

    strategy->name = strdup("Ma première stratégie");
    strategy->strat_func = &strategy_1;
    return strategy;
}
