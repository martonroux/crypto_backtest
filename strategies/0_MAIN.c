/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** 0_MAIN.c
*/

#include "list.h"
#include "strategy.h"

list_t *init_strategies(void)
{
    list_t *list = ll_initialize();

    ll_add_first(list, init_strategy_1());
    return list;
}
