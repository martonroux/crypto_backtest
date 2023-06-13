/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** remove_elem.c
*/

#include "list.h"

void ll_remove_node(list_t *list, node_t *node)
{
    if (list->first == NULL || node == NULL)
        return;

    if (node == list->first)
        list->first = node->next;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;

    free(node);
}
