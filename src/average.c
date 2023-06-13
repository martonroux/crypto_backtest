/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** average.c
*/

/*
 * Function to calculate average
 * @param numbers: list of numbers
 * @param size: size of the list numbers
 * @param start: index at which it should start calculating
 * @return : average of the list
*/
double calc_average(const double *numbers, int size, int start)
{
    double sum = 0;

    if (start < 0)
        start = 0;
    for (int i = start; i < size; i++)
        sum += numbers[i];
    return sum / (size - start);
}
