//
// Created by mazin on 11.03.2025.
//
#include "splitString.h"


char** splitString(const char *input, char delimiter, size_t *tokenCount) {
    char *string = strdup(input);
    if (input == NULL || string == NULL) {
        fprintf(stderr, "Некорректные входные данные\n");
        return NULL;
    }

    size_t maxTokens = 6;
    char **tokens = malloc(maxTokens * sizeof(char *));
    if (tokens == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        free(string);
        return NULL;
    }

    *tokenCount = 0;
    char delimiter_str[3] = {delimiter, '\0'};

    char *token = strtok(string, delimiter_str);
    while (token != NULL) {
        // Если массив токенов заполнен, увеличиваем его размер
        if (*tokenCount >= maxTokens) {
            maxTokens *= 2;
            char **newTokens = realloc(tokens, maxTokens * sizeof(char *));
            if (newTokens == NULL) {
                fprintf(stderr,"Ошибка выделения памяти");
                for (size_t i = 0; i < *tokenCount; i++) {
                    free(tokens[i]);
                }
                free(tokens);
                free(string);
                return NULL;
            }
            tokens = newTokens;
        }

        tokens[*tokenCount] = strdup(token);
        if (tokens[*tokenCount] == NULL) {
            fprintf(stderr, "Ошибка выделения памяти");
            for (size_t i = 0; i < *tokenCount; i++) {
                free(tokens[i]);
            }
            free(tokens);
            free(string);
            return NULL;
        }
        (*tokenCount)++;

        // Получаем следующий токен
        token = strtok(NULL, delimiter_str);
    }

    free(string);
    return tokens;
}
