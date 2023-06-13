/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** list.h
*/

#ifndef C_BACKTEST_LIST_H
    #define C_BACKTEST_LIST_H

    #include <stdlib.h>

typedef struct node_s node_t;

typedef struct node_s {
    node_t *next;
    node_t *prev;
    void *data;
} node_t;

typedef struct list_s {
    node_t *first;
} list_t;


/* FUNCTIONS */

list_t *ll_initialize(void);
void ll_add_first(list_t *list, void *data);
void ll_add_last(list_t *list, void *data);
void ll_remove_node(list_t *list, node_t *node);

#endif
