/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** strategy_1.c
*/

#include <string.h>
#include "strategy.h"
#include "klines.h"

position_t *strategy_1(klines_t **klines, list_t *indics)
{
    printf("Act close: %f\n", get_close(klines)[klines[0]->size]);
    return new_position(klines, 2.0, 1.0, BUY);
}

strategy_t *init_strategy_1(void)
{
    strategy_t *strategy = malloc(sizeof(strategy_t));

    strategy->name = strdup("Ma première stratégie");
    strategy->strat_func = &strategy_1;
    strategy->ratio = 1.0;
    strategy->timeframe = 3600;
    strategy->pair = strdup("BTCUSDT");
    return strategy;
}
