/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** init_indicator.c
*/

#include "klines.h"
#include "my.h"

indicator_t *init_indicator(char *name, indicator_identifier_t identifier, int size)
{
    indicator_t *indicator = malloc(sizeof(indicator_t));

    indicator->name = strdup(name);
    indicator->identifier = identifier;
    indicator->data = NULL;
    indicator->size = size;
    return indicator;
}
