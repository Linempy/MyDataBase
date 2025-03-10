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


Product * inputDataProduct();


#endif //DATABASE_PRODUCTS_H
