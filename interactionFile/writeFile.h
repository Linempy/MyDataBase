//
// Created by mazin on 11.03.2025.
//

#ifndef DATABASE_WRITEFILE_H
#define DATABASE_WRITEFILE_H

#include "../database/productList.h"
#include "../database/tableColumn.h"


/**
 * @brief Функция для записи заголовка (колонок) в файл
 *
 * @param filename - имя файла, куда будет производиться запись
 * @param columns - указатель на колонки таблицы
 * @param delimiter - разделитель
 * @return Результат:
 *  - 1: успешное выполнение функции
 *  - 0: ошибка
 */
bool writeHeader(const char* filename, TableColumn* columns, char delimiter);


/**
 * @brief Функция для записи данных таблицы в файл
 *
 * @param filename - имя файла, куда будет производиться запись
 * @param products - указатель на список продуктов
 * @param delimiter - разделитель
 * @return Результат:
 *  - 1: успешное выполнение функции
 *  - 0: ошибка
 */
bool writeData(const char* filename, ProductList *products, char delimiter);


/**
 * @brief Функция-обертка для записи таблицы в файл
 *
 * @param filename - имя файла, куда будет производиться запись
 * @param products - указатель на список продуктов
 * @param columns - указатель на колонки таблицы
 * @param delimiter - разделитель
 * @return Результат:
 *  - 1: успешное выполнение функции
 *  - 0: ошибка
 */
bool saveTable(const char * filename, ProductList *products, TableColumn *columns, char delimiter);

//FILE* saveOpen(const char* filename, const char* mode);

#endif //DATABASE_WRITEFILE_H
