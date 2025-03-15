//
// Created by mazin on 10.03.2025.
//

#ifndef DATABASE_PRODUCTLIST_H
#define DATABASE_PRODUCTLIST_H

#include "products.h"


/**
 * @brief Структура, представляющая список продуктов.
 *
 * Содержит массив продуктов, их текущее количество и вместимость массива.
 */
typedef struct {
    Product *products; ///< Массив продуктов.
    size_t length;     ///< Текущее количество продуктов.
    size_t capacity;   ///< Вместимость массива продуктов.
} ProductList;


/**
 * @brief Создает новый список продуктов с заданной начальной вместимостью.
 *
 * @param defaultCapacity - начальная вместимость списка продуктов.
 * @return Возвращает ProductList - созданный список продуктов.
 */
ProductList createProductList(size_t defaultCapacity);


/**
 * @brief Безопасно изменяет размер выделенной памяти.
 *
 * @param ptr - указатель на выделенную память.
 * @param newCapacity - новый размер памяти.
 * @return Возвращает void* - указатель на перераспределенную память или NULL в случае ошибки.
 */
void* safeRealloc(void *ptr, size_t newCapacity);


/**
 * @brief Изменяет размер массива продуктов, если это необходимо (элементов меньше в 2 раза, чем вместимость)
 *
 * @param products - указатель на список продуктов.
 * @param defaultCapacity - вместимость по умолчанию.
 */
void reRealloc(ProductList* products, size_t defaultCapacity);


/**
 * @brief Удаляет продукт с указанным идентификатором из списка.
 *
 * @param products - указатель на список продуктов.
 * @param id - идентификатор продукта для удаления.
 * @param defaultCapacity - вместимость по умолчанию.
 */
void removeProduct(ProductList* products, size_t id, size_t defaultCapacity);


/**
 * @brief Добавляет новый продукт в список продуктов.
 *
 * @param productList - указатель на список продуктов.
 * @param newProduct - указатель на новый продукт.
 * @return Возвращает true, если продукт успешно добавлен, иначе false.
 */
bool addProduct(ProductList *productList, Product *newProduct);


/**
 * @brief Освобождает память, выделенную для списка продуктов.
 *
 * @param products - указатель на список продуктов.
 */
void freeProductList(ProductList* products);


/**
 * @brief Проверяет, пуст ли список продуктов.
 *
 * @param products Указатель на список продуктов.
 * @return Возвращает true, если список пуст, иначе false.
 */
bool isEmptyProduct(const ProductList *products);


#endif //DATABASE_PRODUCTLIST_H
