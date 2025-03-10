//
// Created by mazin on 10.03.2025.
//
#include "productList.h"

ProductList createProductList(size_t defaultCapacity) {
    ProductList list;
    list.products = (Product *) malloc(defaultCapacity * sizeof(Product));
    list.size = 0;
    list.capacity = defaultCapacity;
    return list;
}


void* safeRealloc(void *ptr, size_t newSize){
    void *newPtr = realloc(ptr, newSize);
    if (!newSize) {
        printf("Ошибка в выделении памяти!\n");
        free(ptr);
        exit(EXIT_FAILURE);
    }
    return newPtr;
}


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


bool addProduct(ProductList *productList, const Product *newProduct) {
    if(productList->size >= productList->capacity) {
        size_t newCapacity = productList->capacity * 2;

        productList->products = safeRealloc(productList->products,
                                            newCapacity * sizeof(Product));
        productList->capacity = newCapacity;
    }
    productList->products[productList->size] = *newProduct;
    productList->size++;

    return true;
}
