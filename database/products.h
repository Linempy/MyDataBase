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


typedef struct {
    size_t id;
    char name[64];
    char description[255];
    float price;
    float amount;
    size_t category_id;
//    char image_url[255];
} Product;

Product * fillProduct(size_t id, const char *name, const char *description,
                      float price, float amount, size_t category_id);

Product * inputDataProduct();

bool addProduct(Product **product, const Product *newProduct, size_t *count, size_t *capacity);

#endif //DATABASE_PRODUCTS_H
