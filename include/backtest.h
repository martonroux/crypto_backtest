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

void replace_sizes(csv_t **klines, list_t *indics, int size);

#endif
