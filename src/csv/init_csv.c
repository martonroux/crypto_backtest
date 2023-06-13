/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** init_csv.c
*/

#include "csv.h"
#include "my.h"

csv_t **init_csv(char **columns, int size, int nb_tokens)
{
    csv_t **csv = NULL;

    csv = malloc(sizeof(csv_t *) * (nb_tokens + 1));
    csv[nb_tokens] = NULL;
    for (int i = 0; i < nb_tokens; i++) {
        csv[i] = malloc(sizeof(csv_t));
        csv[i]->name = columns[i];
        csv[i]->size = size;
        csv[i]->data = malloc(sizeof(double) * size);
    }
    return csv;
}
