/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** strategy.h
*/

#ifndef C_BACKTEST_STRATEGY_H
    #define C_BACKTEST_STRATEGY_H

    #define BUY 1
    #define SELL 2

    #include "list.h"
    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>

typedef struct position_s position_t;

typedef struct klines_s {
    char *name;
    int size;
    double *data;
} klines_t;

typedef struct strategy_s {
    char *name;
    position_t* (*strat_func)(klines_t **klines, list_t *indics);
} strategy_t;

list_t *init_strategies(void);
position_t *new_position(klines_t **klines, double take_profit, double stop_loss, int side);

/* YOUR STRATEGIES HERE */

strategy_t *init_strategy_1(void);

#endif
