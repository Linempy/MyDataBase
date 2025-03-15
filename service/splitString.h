//
// Created by mazin on 11.03.2025.
//

#ifndef DATABASE_SPLITSTRING_H
#define DATABASE_SPLITSTRING_H

#define MAX_STATIC_SIZE 64

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Разбивает строку на токены по указанному разделителю.
 *
 * @param input - исходная строка
 * @param delimiter - разделитель (например ';')
 * @param tokenCount - указатель на переменную для хранения кол-ва токенов
 * @return массив разделенных строк, заканчивающийся NULL
 */
char** splitString(const char *input, char delimiter, size_t *tokenCount);


#endif //DATABASE_SPLITSTRING_H
