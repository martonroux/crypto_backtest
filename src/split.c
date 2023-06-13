/*
** EPITECH PROJECT, 2023
** c_backtest
** File description:
** split.c
*/

#include "my.h"

char **split(const char* str, char delim, int* num_tokens)
{
    int len = strlen(str);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == delim) {
            count++;
        }
    }
    count++;
    *num_tokens = count;
    char** tokens = (char**)malloc(count * sizeof(char*));
    int start = 0;
    int tokenIndex = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == delim || str[i] == '\0') {
            int tokenLen = i - start;
            tokens[tokenIndex] = (char*)malloc((tokenLen + 1) * sizeof(char));
            strncpy(tokens[tokenIndex], str + start, tokenLen);
            tokens[tokenIndex][tokenLen] = '\0';
            start = i + 1;
            tokenIndex++;
        }
    }
    return tokens;
}
