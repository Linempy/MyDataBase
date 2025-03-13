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


typedef struct {
    size_t id;
    char name[64];
    char description[255];
    float price;
    float amount;
    size_t category_id;
//    char image_url[255];
} Product;

typedef struct {
    size_t nextId;
} IdGenerator;


size_t getNextId(IdGenerator *generator);


Product * fillProductByIdGenerator(IdGenerator *productIdGenerator, char *name, const char *description,
                      float price, float amount, size_t category_id);

Product * fillProductById(size_t id, char *name, const char *description,
                                   float price, float amount, size_t category_id);

Product * inputDataProduct(IdGenerator *productIdGenerator);

size_t * inputIdByProduct(size_t *id);


#endif //DATABASE_PRODUCTS_H
