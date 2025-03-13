//
// Created by mazin on 08.03.2025.
//
#include "products.h"


size_t getNextId(IdGenerator *generator) {
    return generator->nextId++;
}

Product * fillProduct(IdGenerator *productIdGenerator, char *name, const char *description,
                      float price, float amount, size_t category_id) {
    Product *newProduct = (Product *) malloc(sizeof(Product));
    if (!newProduct) {
        printf("Ошибка в выделении памяти!\n");
        return NULL;
    }

    newProduct->id = getNextId(productIdGenerator);
    strncpy(newProduct->name, name, sizeof(newProduct->name) - 1);
    newProduct->name[sizeof(newProduct->name) - 1] = '\0';

    strncpy(newProduct->description, description, sizeof(newProduct->description) - 1);
    newProduct->description[sizeof(newProduct->description) - 1] = '\0';

    newProduct->price = price;
    newProduct->amount = amount;
    newProduct->category_id = category_id;

    return newProduct;
}


Product * inputDataProduct(IdGenerator *productIdGenerator) {
    char name[64];
    char description[255];
    float price;
    float amount;
    size_t category_id;

    if (!inputString(name,
                     sizeof(name),
                     "Введите наименование товара (макс. 63 символа): ")) {
        return NULL;
    }

    if (!inputString(description,
                     sizeof(description),
                     "Введите описание товара (макс. 254 символа): ")) {
        return NULL;
    }

    if (!inputNumber(&price, "%f",
                     "Введите цену товара: ", "Ошибка: введена некорректная цена.\n")) {
        return NULL;
    }

    if (!inputNumber(&amount, "%f",
                     "Введите количество товара: ", "Ошибка: введено некорректное количество.\n")) {
        return NULL;
    }

    if (!inputNumber(&category_id, "%zu",
                     "Введите категорию товара: ", "Ошибка: введена некорректная категория.\n")) {
        return NULL;
    }


    return fillProduct(productIdGenerator, name, description, price, amount, category_id);
}


size_t * inputIdByProduct(size_t *id) {
    if (!inputNumber(id, "%zu",
                     "Введите ID товара: ", "Ошибка: некорректный ID\n")) {
        return NULL;
    }
}


