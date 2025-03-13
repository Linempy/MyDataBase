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

void removeProduct(ProductList* products, size_t id, size_t defaultCapacity);

bool addProduct(ProductList *productList, Product *newProduct);

void freeProductList(ProductList* products);

bool isEmptyProduct(const ProductList *products);


#endif //DATABASE_PRODUCTLIST_H
