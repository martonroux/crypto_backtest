/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** create_rsi.c
*/

#include "klines.h"
#include "my.h"

double *calc_wilder_smoothing(double *numbers, int period, int size)
{
    double *res = malloc(sizeof(double) * size);
    double a = 1.0 / period;
    double min_a = (period - 1.0) / period;
    res[0] = numbers[0];

    for (int i = 1; i < size; i++) {
        res[i] = a * numbers[i] + min_a * res[i - 1];
    }
    return res;
}

double *get_ups(const double *deltas, int size)
{
    double *ups = malloc(sizeof(double) * size);

    for (int j = 0; j < size; j++) {
        if (deltas[j] > 0) {
            ups[j] = deltas[j];
        } else {
            ups[j] = 0;
        }
    }
    return ups;
}

double *get_downs(const double *deltas, int size)
{
    double *downs = malloc(sizeof(double) * size);

    for (int j = 0; j < size; j++) {
        if (deltas[j] > 0) {
            downs[j] = 0;
        } else {
            downs[j] = ABS(deltas[j]);
        }
    }
    return downs;
}

double *get_deltas(const double *close, int size)
{
    double *deltas = malloc(sizeof(double) * size);

    for (int j = 1; j < size; j++)
        deltas[j] = close[j] - close[j - 1];
    return deltas;
}

double *calc_rsi(const double *close, int size, int period)
{
    double *rsi = malloc(sizeof(double) * size);
    double *deltas = get_deltas(close, size);
    double *ups = get_ups(deltas, size);
    double *downs = get_downs(deltas, size);
    double *avg_ups = calc_wilder_smoothing(ups, period, size);
    double *avg_downs = calc_wilder_smoothing(downs, period, size);

    for (int i = period; i < size; i++) {
        double rs = avg_ups[i] / avg_downs[i];
        rsi[i] = round_to(100 - (100 / (1 + rs)), 2);
    }

    free(ups);
    free(downs);
    free(avg_ups);
    free(avg_downs);
    free(deltas);
    return rsi;
}

indicator_t *create_rsi(csv_t **klines, int timeline)
{
    printf("Creating RSI data...\n");
    indicator_t *indicator = init_indicator("rsi", RSI_ID, klines[0]->size);
    rsi_t *rsi = malloc(sizeof(rsi_t));

    rsi->timeline = timeline;
    rsi->data = calc_rsi(get_close(klines), indicator->size, timeline);
    indicator->data = rsi;
    return indicator;
}
