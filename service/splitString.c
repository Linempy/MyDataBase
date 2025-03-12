//
// Created by mazin on 11.03.2025.
//
#include "splitString.h"

void removeTrailingDelimiter(char *str, char delimiter) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == delimiter) {
        str[len - 1] = '\0';
    }
}

char** splitString(const char *input, char delimiter, size_t *tokenCount) {
    char *string = strdup(input);
    if (string == NULL) {
        perror("Ошибка выделения памяти");
        return NULL;
    }

    int maxTokens = 10;
    char **tokens = malloc(maxTokens * sizeof(char *));
    if (tokens == NULL) {
        perror("Ошибка выделения памяти");
        free(string);
        return NULL;
    }

    *tokenCount = 0;

    char *token = strtok(string, &delimiter);
    while (token != NULL && *tokenCount < maxTokens) {
        tokens[*tokenCount] = strdup(token);
        if (tokens[*tokenCount] == NULL) {
            perror("Ошибка выделения памяти");
            for (int i = 0; i < *tokenCount; i++) {
                free(tokens[i]);
            }
            free(tokens);
            free(string);
            return NULL;
        }
        (*tokenCount)++;
        token = strtok(NULL, &delimiter);
    }

    free(string);
    removeTrailingDelimiter(tokens, delimiter);

    return tokens;
}