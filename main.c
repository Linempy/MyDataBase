#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "products.h"


void printProduct(const Product *product) {
    printf("ID: %zu\n", product->id);
    printf("Название: %s\n", product->name);
    printf("Описание: %s\n", product->description);
    printf("Цена: %.2f\n", product->price);
    printf("Количество: %.2f\n", product->amount);
    printf("Категория: %zu\n", product->category_id);
    printf("----------------------------\n");
}

void printProducts (const Product *products, size_t count) {
    for (size_t i = 0; i < count; i++) {
        // Используем арифметику указателей для доступа к элементам массива
        printProduct(products + i); // Эквивалентно &products[i]
    }
}

int main(void) {
    system("chcp 65001");
    size_t defaultSize = 4;

    Product *products = (Product *)malloc(defaultSize * sizeof(Product));
    if (products == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    Product *product = inputDataProduct();
    size_t count = 0;

    addProduct(&products, product, &count, &defaultSize);
    printProducts(products, 2);

    free(product);
    free(products);
    return 0;
}
