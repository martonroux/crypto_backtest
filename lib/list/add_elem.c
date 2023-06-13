/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** add_elem.c
*/

#include "list.h"

void ll_add_first(list_t *list, void *data)
{
    node_t *node = malloc(sizeof(node_t));

    node->data = data;
    node->next = list->first;
    node->prev = NULL;

    if (list->first != NULL)
        list->first->prev = node;
    list->first = node;
}

void ll_add_last(list_t *list, void *data)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *current = NULL;

    node->data = data;
    node->next = NULL;

    if (list->first == NULL) {
        node->prev = NULL;
        list->first = node;
    } else {
        current = list->first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        node->prev = current;
    }
}
