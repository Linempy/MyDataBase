//
// Created by mazin on 09.03.2025.
//

#ifndef DATABASE_TABLECOLUMN_H
#define DATABASE_TABLECOLUMN_H

#include <stddef.h>
#include <stdlib.h>
#include "../output/formatField.h"
#include "productList.h"
#include "products.h"
#include "../output/formatField.h"


/**
 * @brief Структура, представляющая столбец таблицы.
 *
 * Содержит информацию о заголовке столбца, смещении поля в структуре Product,
 * формате вывода, ширине столбца и количестве элементов.
 */
typedef struct {
    const char* header; ///< Заголовок столбца
    size_t offset;      ///< Смещение поля в структуре Product.
    FormatField format; ///< Формат вывода данных (например, строка, число и т.д.).
    size_t width;       ///< Ширина столбца (если 0, ширина определяется автоматически).
    size_t count;       ///< Количество элементов в столбце (если применимо).
} TableColumn;


/**
 * @brief Структура, представляющая список столбцов таблицы.
 *
 * Содержит массив столбцов (TableColumn), их текущее количество и вместимость.
 */
typedef struct {
    TableColumn *columns;
    size_t count;
    size_t capacity;
} TableColumnList;


/**
 * @brief Создает новый список столбцов с заданной начальной вместимостью.
 *
 * @param initialCapacity - начальная вместимость списка столбцов.
 * @return Возвращает TableColumnList - созданный список столбцов
 */
TableColumnList createTableColumnList(size_t initialCapacity);


/**
 * @brief Добавляет новый столбец в список столбцов.
 *
 * @param list - указатель на список столбцов.
 * @param header - заголовок нового столбца.
 * @param offset - смещение поля в структуре Product.
 * @param format - формат вывода данных.
 * @param width - ширина столбца (если 0, ширина определяется автоматически).
 */
void addTableColumn(TableColumnList *list, const char *header, size_t offset, FormatField format, size_t width);


/**
 * @brief Освобождает память, выделенную для списка столбцов.
 *
 * @param list - указатель на список столбцов.
 */
void freeTableColumnList(TableColumnList *list);


/**
 * @brief Добавляет столбцы по умолчанию для структуры Product.
 *
 * Столбцы добавляются в список с предопределенными заголовками, смещениями и форматами.
 *
 * @param list - указатель на список столбцов.
 */
void addDefaultProductColumns(TableColumnList *list);

#endif //DATABASE_TABLECOLUMN_H
