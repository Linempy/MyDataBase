//
// Created by mazin on 12.03.2025.
//

#ifndef DATABASE_CLI_H
#define DATABASE_CLI_H

#include <stdio.h>
#include "../lexicon/lexicon.h"
#include "../service/getLine.h"
#include "../database/products.h"
#include "../database/productList.h"
#include "../database/tableColumn.h"
#include "../output/outputConsoleDB.h"
#include "../interactionFile/writeFile.h"
#include "../interactionFile/readFile.h"
#include "../sorted/sortedByField.h"
#include "../service/getLine.h"

/** Перечисления для кодов ошибок
 * SUCCESS - успешное выполнение команды
 * EXIT - код для завершения программы
 * OTHER_COMMAND - была введена не команда
 * ERROR - ошибка во время выполнения программы
 */
typedef enum {
    SUCCESS = 1,
    EXIT = 2,
    OTHER_COMMAND = 3,
    ERROR = 0,
} CODE_HANDLER;

/**
 * Функция для вывода информации о приложении
 */
void printINFO();

/**
 * Функция для вывода сообщения-помощника
 */
void printHELP();


/**
 * @brief Функция, которая ждет от пользователя ввод команды
 *
 * @param act - статический буффер, в который запишется название команды, которое ввел пользователь
 * @return Результат:
 *  - 1: успешное выполнение функции
 *  - 0: ошибка
 */
bool chooseAct(char* act);

/**
 * @brief Функция-обработчик сообщений от пользователя
 *
 * @param productList - указатель на исходный список продуктов
 * @param columnList - указатель на исходную таблицу
 * @param message - сообщение от пользователя
 * @param productIdGenerator - указатель на объект для autoincrement поля id
 * @param filename - имя файла
 * @return Результатом является код CODE_HANDLER:
 * SUCCESS - успешное выполнение команды
 * EXIT - код для завершения программы
 * OTHER_COMMAND - была введена не команда
 * ERROR - ошибка во время выполнения программы
 */
CODE_HANDLER handlerMessage(ProductList *productList, TableColumnList *columnList,
                    char *message, IdGenerator *productIdGenerator, char *filename);

/**
 * @brief Функция для записи в переменную имя файла
 *
 * @param filename - буфер для записи имя файла
 * @param filenameSize - размер буфера
 * @return Результат:
 *  - 1: успешное выполнение функции
 *  - 0: ошибка
 */
bool setFileName(char *filename, size_t filenameSize);


#endif //DATABASE_CLI_H
