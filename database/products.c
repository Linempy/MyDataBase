//
// Created by mazin on 08.03.2025.
//
#include "products.h"

Product * fillProduct(size_t id, const char *name, const char *description,
                      float price, float amount, size_t category_id) {
    Product *newProduct = (Product *) malloc(sizeof(Product));
    if (!newProduct) {
        printf("Ошибка в выделении памяти!\n");
        return NULL;
    }

    newProduct->id = id;
    strncpy(newProduct->name, name, sizeof(newProduct->name) - 1);
    newProduct->name[sizeof(newProduct->name) - 1] = '\0';

    strncpy(newProduct->description, description, sizeof(newProduct->description) - 1);
    newProduct->description[sizeof(newProduct->description) - 1] = '\0';

    newProduct->price = price;
    newProduct->amount = amount;
    newProduct->category_id = category_id;

    return newProduct;
}


Product * inputDataProduct() {
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
                     "Введите цену товара: ", "Ошибка: введена некорректная цена.")) {
        return NULL;
    }

    if (!inputNumber(&amount, "%f",
                     "Введите количество товара: ", "Ошибка: введено некорректное количество.")) {
        return NULL;
    }

    if (!inputNumber(&category_id, "%zu",
                     "Введите категорию товара: ", "Ошибка: введена некорректная категория.")) {
        return NULL;
    }

    // Нужно доставать Id
    return fillProduct(0, name, description, price, amount, category_id);
}

