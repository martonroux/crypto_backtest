/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** print_exit.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

static int exec_param(const char *str, va_list *ap, int i, int pt)
{
    char *params = "sdc";
    char c = str[i];

    if (strchr(params, c)) {
        if (c == 's')
            fprintf(stderr, "%s", va_arg(*ap, char *));
        if (c == 'd')
            fprintf(stderr, "%d", va_arg(*ap, int));
        if (c == 'c')
            fprintf(stderr, "%c", va_arg(*ap, int), 2);
        return 1;
    }
    return 0;
}

void print_exit(const char *str, ...)
{
    int i = 0;
    int pt = 0;
    va_list ap;

    va_start(ap, str);
    for (; str[i]; i++) {
        if (str[i] == '%' && exec_param(str, &ap, ++i, pt) == 1)
            (void)pt;
        else
            fprintf(stderr, "%c", str[i]);
    }
    va_end(ap);
    exit(EXIT_FAILURE);
}
