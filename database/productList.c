//
// Created by mazin on 10.03.2025.
//
#include "productList.h"


ProductList createProductList(size_t defaultCapacity) {
    ProductList list = {NULL, 0, 0};

    if (defaultCapacity == 0) {
        fprintf(stderr, "Ошибка: неверные аргументы.\n");
        return list;
    }

    list.products = (Product *) malloc(defaultCapacity * sizeof(Product));
    if (!list.products) {
        perror("Ошибка выделения памяти");
        return list;
    }
    list.length = 0;
    list.capacity = defaultCapacity;
    return list;
}


void* safeRealloc(void *ptr, size_t newSize){
    void *newPtr = realloc(ptr, newSize);
    if (!newPtr && newSize != 0) {
        fprintf(stderr, "Ошибка в выделении памяти!\n");
        free(ptr);
        return NULL;
    }
    return newPtr;
}


bool addProduct(ProductList *productList, Product *newProduct) {
    if (!productList || !newProduct) {
        fprintf(stderr, "Ошибка: неверные аргументы\n");
        return false;
    }

    if(productList->length >= productList->capacity) {
        size_t newCapacity = productList->capacity * 2;
        if (newCapacity < productList->capacity) {
            fprintf(stderr, "Ошибка: переполнение при вычислении newCapacity.\n");
            return false;
        }
        printf("начало");
        Product *newProducts = safeRealloc(productList->products,
                                            newCapacity * sizeof(Product));
        printf("конец");
        if (!newProducts) {
            return false;
        }
        productList->products = newProducts;
        productList->capacity = newCapacity;
    }

    productList->products[productList->length] = *newProduct;
    productList->length++;

    free(newProduct);

    return true;
}


void reRealloc(ProductList* products, size_t defaultCapacity) {
    if (!products) {
        fprintf(stderr, "Ошибка: неверные аргументы\n");
        return;
    }

    size_t newCapacity = products->capacity / 2;
    if (products->length <= newCapacity && newCapacity >= defaultCapacity) {
        Product *newProducts = safeRealloc(products->products,
                                         newCapacity * sizeof(Product));
        if (!newProducts) {
            return;
        }
        products->products = newProducts;
        products->capacity = newCapacity;
    } else fprintf(stderr, "Уменьшение памяти не требуется\n");

}


size_t findProductIndexById(const ProductList *products, size_t id) {
    for(Product *currProduct = products->products, *endProduct = products->products + products->length;
        currProduct < endProduct; currProduct++) {
        if (id == currProduct->id) {
            return currProduct - products->products;
        }
    }
    return products->length;
}

// Удаление продукта по индексу
void removeProduct(ProductList* products, size_t id, size_t defaultCapacity) {
    if (!products) {
        fprintf(stderr, "Ошибка: неверные аргументы\n");
        return;
    }

    size_t index = findProductIndexById(products, id);
    printf("%zu", index);
    if (index >= products->length) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    memmove(&products->products[index],
            &products->products[index + 1],
            (products->length - index - 1) * sizeof(Product));
    products->length--;

    reRealloc(products, defaultCapacity);
}

// Освобождение памяти
void freeProductList(ProductList* products) {
    if (!products) {
        return;
    }

    free(products->products);
    products->products = NULL;

    products->length = 0;
    products->capacity = 0;
}

bool isEmptyProduct(const ProductList *products) {
    return products && products->products == NULL &&
           products->length == 0 &&
           products->capacity == 0;
}
