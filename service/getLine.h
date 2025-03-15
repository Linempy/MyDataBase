//
// Created by mazin on 28.02.2025.
//

#ifndef UNTITLED_GETLINE_H
#define UNTITLED_GETLINE_H

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>




/**
 * @brief Функция для чтения строки фиксированной длины
 *
 * @note Символы, которые не были прочитаны будут обрезаны.
 *
 * @param buffer - исходная строка
 * @param bufferSize - размер итоговой строки
 * @return возвращает строку размера bufferSize
 */
bool readFixedLengthString(char *buffer, int bufferSize);


/**
 * @brief Функция для чтения чисел
 *
 * @param value - указатель на переменную , куда будет записано число (вещ. или целое)
 * @param format  - форматированный спецификатор
 * @return Результат:
 *  - 1: успешное выполнение функции
 *  - 0: ошибка
 */
bool readNumber(void *value, const char *format);


/**
 * @brief Функция-обертка для функции readFixedLengthString
 *
 * @param buffer - указатель на переменную, куда будет записана строка
 * @param bufferSize - размер строки
 * @param prompt - текстовое сообщение, которое увидит пользователь перед тем как ввести строку
 * @return Результат:
 * - 1: успешное выполнение функции
 * - 0: ошибка
 */
bool inputString(char *buffer, int bufferSize, const char *prompt);


/**
 * @brief Функция-обертка для функции readNumber.
 *
 * @param value - указатель на переменную, куда будет записано число
 * @param format - форматированный спецификатор
 * @param prompt - текстовое сообщение, которое увидит пользователь перед тем как ввести число
 * @param errorMessage - сообщение об ошибке
 * @return Результат:
 * - 1: успешное выполнение функции
 * - 0: ошибка
 */
bool inputNumber(void *value, const char *format, const char *prompt, const char *errorMessage);

#endif //UNTITLED_GETLINE_H
