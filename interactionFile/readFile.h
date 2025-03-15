//
// Created by mazin on 11.03.2025.
//

#ifndef DATABASE_READFILE_H
#define DATABASE_READFILE_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../service/splitString.h"
#include "../database/productList.h"
#include "../database/products.h"
#include "../database/tableColumn.h"
#include "../output/outputConsoleDB.h"


/**
 * @brief Функция для чтения строки
 *
 * @param file - исходный файл
 * @return Возвращает прочитанную строку или NULL в случае ошибки:
 */
char* readLine(FILE* file);


/**
 * @brief Функция для чтения заголовка таблицы в файле
 *
 * @param filename - имя файла
 * @param delimiter - разделитель
 * @param defaultCapacity - стандартный размер TableColumnList
 * @return Возвращает таблицу (структуру TableColumnList)
 */
TableColumnList readHeader(char * filename, char delimiter, size_t defaultCapacity);


/**
 * @brief Преобразует строку в значение типа size_t.
 *
 * @param str - входная строка.
 * @param result - указатель на переменную для записи результата.
 * @return Результат:
 *   - 1: успешное выполнение программы.
 *   - 0: Строка пустая или NULL.
 */
bool parseSizeT(const char *str, size_t *result);


/**
 * @brief Преобразует строку в значение типа float.
 *
 * @param str - входная строка.
 * @param result - указатель на переменную для записи результата.
 * @return Результат:
 *   - 1: успешное выполнение программы.
 *   - 0: пустая строка или NULL.
 */
bool parseFloat(const char *str, float* result);


/**
 * @brief Освобождает память, выделенную для массива строк.
 *
 * @param data - указатель на массив строк
 * @param count - количество строк в массиве
 */
void freeArrayData(char** data, size_t count);


/**
 * @brief Функция для чтения данных таблицы в файле
 *
 * @param filename - имя файла
 * @param delimiter - разделитель
 * @param products - указатель на список продуктов
 * @param idGenerator - указатель на объект для autoincrement поля id
 * @return Возвращает структуру списка продуктов
 */
ProductList readData(char * filename, char delimiter, ProductList *products,
                     IdGenerator *idGenerator);


/**
 * @brief Функция-обертка для загрузки файла (таблицы)
 *
 * @param products - указатель на список продуктов
 * @param columns - указатель на колонки таблицы
 * @param filename - имя файла
 * @param delimiter - разделитель
 * @param idGenerator - указатель на объект для autoincrement поля id
 * @param defaultSizeProdList - стандартный размер списка продуктов в ProductList
 * @return
 */
bool loadTable(ProductList *products,TableColumnList *columns,
              char * filename, char delimiter, IdGenerator *idGenerator, size_t defaultSizeProdList);


#endif //DATABASE_READFILE_H
