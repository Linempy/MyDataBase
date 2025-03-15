//
// Created by mazin on 09.03.2025.
//

#ifndef DATABASE_FORMATFIELD_H
#define DATABASE_FORMATFIELD_H

#include <stddef.h>


/**
 * @brief Тип указателя на функцию форматирования данных.
 *
 * Функция форматирует данные и записывает результат в буфер.
 * Используется для преобразования данных произвольного типа в строковое представление.
 *
 * @param dest - буфер, в который записывается отформатированная строка.
 * @param destSize - размер буфера `dest` в байтах. Используется для предотвращения переполнения.
 * @param field - указатель на данные, которые нужно отформатировать.
 */
typedef void (*FormatField)(char* dest, size_t destSize, const void* field);


/**
 * @brief Функция для форматирования вещественных чисел в строку
 *
 * @param dest - буфер для записи результата
 * @param destSize - размер буфера
 * @param field - указатель на вещ. число (значение соответствующего поля)
 */
void formatFloat(char* dest, size_t destSize, const void* field);


/**
 * @brief Функция для форматирования строки
 *
 * @param dest - буфер для записи результата
 * @param destSize - размер буфера
 * @param field - указатель на строку (значение соответствующего поля)
 */
void formatString(char* dest, size_t destSize, const void* field);


/**
 * @brief Функция для форматирования целых чисел
 *
 * @param dest - буфер для записи результата
 * @param destSize - размер буфера
 * @param field - указатель на число (значение соответствующего поля)
 */
void formatSizeT(char* dest, size_t destSize, const void* field);


#endif //DATABASE_FORMATFIELD_H
