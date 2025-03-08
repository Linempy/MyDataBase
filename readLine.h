//
// Created by mazin on 28.02.2025.
//

#ifndef UNTITLED_GETLINE_H
#define UNTITLED_GETLINE_H

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


/* Функция считывания строки до нажатия на Enter
*/
bool readFixedLengthString(char *buffer, size_t bufferSize);
bool readNumber(void *value, const char *format);
bool inputString(char *buffer, size_t bufferSize, const char *prompt);
bool inputNumber(void *value, const char *format, const char *prompt, const char *errorMessage);

#endif //UNTITLED_GETLINE_H
