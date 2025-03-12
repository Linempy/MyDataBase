//
// Created by mazin on 28.02.2025.
//
#include "getLine.h"


bool readFixedLengthString(char *buffer, int bufferSize) {
    if (!buffer || bufferSize < 2) {
        return false;
    }
    if (fgets(buffer, bufferSize, stdin)) {
        size_t len = strlen(buffer);

        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        } else {
            printf("Предупреждение: строка была обрезана до %d символов.\n", bufferSize - 1);

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
        return true;
    }

    return false;
}


bool readNumber(void *value, const char *format) {
    if (scanf(format, value) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        return false;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    return true;
}


bool inputString(char *buffer, int bufferSize, const char *prompt) {
    printf("%s", prompt);
    if (!readFixedLengthString(buffer, bufferSize)) {
        printf("Ошибка при вводе строки!\n");
        return false;
    }
    return true;
}


bool inputNumber(void *value, const char *format, const char *prompt, const char *errorMessage) {
    printf("%s", prompt);
    if (!readNumber(value, format)) {
        printf("%s\n", errorMessage);
        return false;
    }
    return true;
}
