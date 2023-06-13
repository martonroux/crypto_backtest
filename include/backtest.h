/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** backtest.h
*/

#ifndef C_BACKTEST_BACKTEST_H
    #define C_BACKTEST_BACKTEST_H

    #define BUY 1
    #define SELL 2

    #include "csv.h"
    #include "list.h"

extern int act_strategy;

typedef struct position_s {
    double start;
    double open;
    double capital;
    double take_profit;
    double stop_loss;
    double leverage;
    int side;
    int strategy_id;
} position_t;

void launch_backtest(klines_t **klines, list_t *indics, list_t *strategies);
void replace_sizes(klines_t **klines, list_t *indics, int size);

#endif
