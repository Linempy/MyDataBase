//
// Created by mazin on 10.03.2025.
//

#ifndef DATABASE_PRODUCTLIST_H
#define DATABASE_PRODUCTLIST_H

#include "products.h"

typedef struct {
    Product *products;
    size_t length;
    size_t capacity;
} ProductList;

ProductList createProductList(size_t defaultCapacity);

void* safeRealloc(void *ptr, size_t newCapacity);


void reRealloc(ProductList* products, size_t defaultCapacity);

void removeProduct(ProductList* products, size_t index, size_t defaultCapacity);

Product * fillProduct(size_t id, const char *name, const char *description,
                      float price, float amount, size_t category_id);


bool addProduct(ProductList *productList, const Product *newProduct);

void freeProductList(ProductList* products);

#endif //DATABASE_PRODUCTLIST_H
