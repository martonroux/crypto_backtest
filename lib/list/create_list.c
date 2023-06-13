/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** create_list.c
*/

#include "list.h"

list_t *ll_initialize(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->first = NULL;
    return list;
}
