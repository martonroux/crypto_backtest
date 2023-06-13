/*
** EPITECH PROJECT, 2023
** CRYPTO_BACKTEST
** File description:
** create_random_ids.c
*/

#include <sys/time.h>
#include "strategy.h"

bool is_unique_id(list_t *strategies, int id)
{
    strategy_t *strategy = NULL;

    for (node_t *nde = strategies->first; nde; nde = nde->next) {
        strategy = nde->data;
        if (strategy->id == id)
            return false;
    }
    return true;
}

void create_random_ids(list_t *strategies)
{
    strategy_t *strategy = NULL;
    int id;

    srand(time(NULL));
    for (node_t *nde = strategies->first; nde; nde = nde->next) {
        strategy = nde->data;
        while (is_unique_id(strategies, (id = rand())) == false);
        strategy->id = id;
    }
}
