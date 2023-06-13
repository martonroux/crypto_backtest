/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** klines.h
*/

#ifndef C_BACKTEST_KLINES_H
    #define C_BACKTEST_KLINES_H

    /* HERE ARE DEFINED THE COLUMN NAMES OF THE CSV DATA */

    #define START_NAME "start"
    #define OPEN_NAME "open"
    #define HIGH_NAME "high"
    #define LOW_NAME "low"
    #define CLOSE_NAME "close"
    #define VOLUME_NAME "volume"
    #define END_NAME "end"
    #define QUOTE_ASSET_VOLUME_NAME "quote asset volume"
    #define NUMBER_TRADES_NAME "number trades"
    #define TAKER_BUY_BASE_ASSET_VOLUME_NAME "taker buy base asset volume"
    #define TAKER_BUY_QUOTE_ASSET_VOLUME_NAME "taker buy quote asset volume"

    #include "csv.h"

typedef struct rsi_s {
    int timeline;
    double *data;
} rsi_t;

typedef struct sma_s {
    int timeline;
    double *data;
} sma_t;

typedef struct ema_s {
    int timeline;
    double *data;
} ema_t;

typedef enum indicator_identifier_s {
    NONE = 0,
    RSI_ID = 1,
    SMA_ID = 2,
    EMA_ID = 3,
    CCI_ID = 4
} indicator_identifier_t;

typedef struct indicator_s {
    indicator_identifier_t identifier;
    char *name;
    int size;
    void *data;
} indicator_t;

typedef struct timeframes_s {
    int timeframe;
    klines_t **klines;
} timeframes_t;

/* FUNCTIONS TO GET COLUMNS OF KLINES */

double *get_start(klines_t **klines);
double *get_close(klines_t **klines);
double *get_end(klines_t **klines);
double *get_high(klines_t **klines);
double *get_low(klines_t **klines);
double *get_open(klines_t **klines);
double *get_volume(klines_t **klines);

/* FUNCTIONS TO CREATE INDICATORS */

indicator_t *init_indicator(char *name, indicator_identifier_t identifier, int size);
indicator_t *create_rsi(klines_t **klines, int timeline);

#endif
