/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** strategy_2.c
*/

#include <string.h>
#include "strategy.h"
#include "klines.h"

position_t *strategy_2(klines_t **klines, list_t *indics)
{
    printf("Act close: %f\n", get_close(klines)[klines[0]->size]);
    return new_position(klines, 2.0, 1.0, BUY);
}

strategy_t *init_strategy_2(void)
{
    strategy_t *strategy = malloc(sizeof(strategy_t));

    strategy->name = strdup("Ma deuxième stratégie");
    strategy->strat_func = &strategy_2;
    strategy->ratio = 0.5;
    strategy->timeframe = 3600;
    strategy->pair = strdup("BTCUSDT");
    return strategy;
}
