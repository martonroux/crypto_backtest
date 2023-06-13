/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** round.c
*/

#include <math.h>

double round_to(double nb, int precision)
{
    double prec = pow(10, precision);
    double temp_nb = nb * prec;

    return round(temp_nb) / prec;
}
