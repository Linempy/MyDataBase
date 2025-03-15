//
// Created by mazin on 09.03.2025.
//

#ifndef DATABASE_OUTPUTCONSOLEDB_H
#define DATABASE_OUTPUTCONSOLEDB_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../database/tableColumn.h"
#include "../database/products.h"
#include "../database/productList.h"
#include "formatField.h"


/**
 * @brief Вычисляет ширину столбцов таблицы на основе данных продуктов
 *
 * @param products - указатель на список продуктов
 * @param columns - указатель на список столбцов таблицы
 * @param numColumns - кол-во колонок
 */
void calculateColumnWidths(const ProductList *products, TableColumn* columns, size_t numColumns);

/**
 * @brief Функция для вывода заголовков таблицы
 *
 * @param columns - указатель на список столбцов таблицы
 * @param numColumns - кол-во столбцов
 */
void printTableHeaders(TableColumn* columns, size_t numColumns);

/**
 * @brief Функция для вывода разделительной линии между заголовком и данными
 *
 * @param columns - указатель на список столбцов таблицы
 * @param numColumns - кол-во столбцов
 */
void printTableSeparator(TableColumn* columns, size_t numColumns);


/**
 * @brief Функция для форматированного вывода данных таблицы
 *
 * @param products - указатель на список продуктов
 * @param columns - указатель на столбцы таблицы
 * @param numColumns - кол-во столбцов
 */
void printTableData(const ProductList *products, TableColumn* columns, size_t numColumns);


/**
 * @brief Функция-обертка для централизованного вывода итоговой форматированной таблицы в консоль
 *
 * @param products - указатель на список продуктов
 * @param columns - указатель на колонки таблицы
 * @param numColumns - кол-во колонок
 */
void printTable(const ProductList *products, TableColumn* columns, size_t numColumns);



#endif //DATABASE_OUTPUTCONSOLEDB_H
