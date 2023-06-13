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

typedef struct cci_s {
    csv_t **columns;            // TODO: complete data in struct
} cci_t;

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



/* FUNCTIONS TO GET COLUMNS OF KLINES */

double *get_start(csv_t **klines);
double *get_close(csv_t **klines);
double *get_end(csv_t **klines);
double *get_high(csv_t **klines);
double *get_low(csv_t **klines);
double *get_open(csv_t **klines);
double *get_volume(csv_t **klines);

/* FUNCTIONS TO CREATE INDICATORS */

indicator_t *init_indicator(char *name, indicator_identifier_t identifier, int size);
indicator_t *create_rsi(csv_t **klines, int timeline);

#endif
