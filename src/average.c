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
 * @return : average of the list
*/
double calc_average(const double *numbers, int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
        sum += numbers[i];
    return sum / size;
}
