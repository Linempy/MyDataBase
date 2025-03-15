//
// Created by mazin on 08.03.2025.
//

#ifndef DATABASE_PRODUCTS_H
#define DATABASE_PRODUCTS_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../service/getLine.h"


/**
 * @brief Структура, представляющая продукт.
 *
 * Содержит информацию о продукте, включая его идентификатор, название, описание,
 * цену, количество и идентификатор категории.
 */
typedef struct {
    size_t id;              ///< Уникальный идентификатор продукта.
    char name[64];          ///< Название продукта (максимум 63 символа + '\0').
    char description[255];  ///< Описание продукта (максимум 254 символа + '\0').
    float price;            ///< Цена продукта.
    float amount;           ///< Количество продукта в наличии.
    size_t category_id;     ///< Идентификатор категории продукта.
//    char image_url[255];
} Product;


/**
 * @brief Структура, представляющая генератор уникальных идентификаторов.
 *
 * Используется для генерации уникальных ID для продуктов.
 */
typedef struct {
    size_t nextId; ///< Следующий идентификатор.
} IdGenerator;


/**
 * @brief Генерирует и возвращает следующий уникальный идентификатор.
 *
 * @param generator - указатель на генератор идентификаторов.
 * @return Возвращает size_t - следующий уникальный идентификатор.
 */
size_t getNextId(IdGenerator *generator);



/**
 * @brief Создает продукт и заполняет его переданными данными с использованием генератора идентификаторов.
 *
 * @param productIdGenerator - указатель на генератор идентификаторов
 * @param name - название продукта
 * @param description - описание продукта
 * @param price - цена продукта
 * @param amount - количество продукта
 * @param category_id - идентификатор категории продукта
 * @return Возвращает Product* - указатель на созданный продукт или NULL в случае ошибки
 */
Product * fillProductByIdGenerator(IdGenerator *productIdGenerator, char *name, const char *description,
                      float price, float amount, size_t category_id);


///**
// * @brief Создает продукт и заполняет его переданными данными без использования генератора идентификаторов.
// *
// * @param id - идентификатор продукта
// * @param name - название продукта
// * @param description - описание продукта
// * @param price - цена продукта
// * @param amount - количество продукта
// * @param category_id - идентификатор категории продукта
// * @return Возвращает Product* - указатель на созданный продукт или NULL в случае ошибки
// */
//Product * fillProductById(size_t id, char *name, const char *description,
//                                   float price, float amount, size_t category_id);


/**
 * @brief Запрашивает у пользователя данные для создания продукта.
 *
 * @param productIdGenerator - указатель на генератор идентификаторов.
 * @return Возвращает Product* - указатель на созданный продукт или NULL в случае ошибки.
 */
Product * inputDataProduct(IdGenerator *productIdGenerator);


/**
 * @brief Запрашивает у пользователя ввод идентификатора продукта.
 *
 * @param id - указатель на переменную, в которую будет записан идентификатор.
 * @return Возвращает size_t* - указатель на введенный идентификатор или NULL в случае ошибки.
 */
size_t * inputIdByProduct(size_t *id);


#endif //DATABASE_PRODUCTS_H
