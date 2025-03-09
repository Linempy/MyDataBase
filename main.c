#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "database/products.h"
#include "output/outputConsoleDB.h"
#include "output/tableColumn.h"
#include "service/visualWidth.h"


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
    const Product *beg, *end;

    for (beg = products, end = products + count; beg < end; beg++) {
        printProduct(beg);
    }
}


int main(void) {

    system("chcp 65001");
    size_t defaultSize = 4;

//    Product *products = (Product *)malloc(defaultSize * sizeof(Product));
//    if (products == NULL) {
//        printf("Ошибка выделения памяти!\n");
//        return 1;
//    }
    size_t count = 0;
    const char *str = "Привет, Hello!"; // Строка с русскими, английскими буквами и смайликом
    printf("Визуальная ширина строки: %zu\n", visualWidth(str)); // 20
//    addProduct(&products, product, &count, &defaultSize);

    Product products[] = {
            {1, "Alice Johnson", "dsafdsfsf", 20, 3.8f, 1},
            {2, "Bob Smith with a very long name that exceeds the limit",
             "fdasfsdf",21, 3.5f, 2},
            {3, "Charlie Brown", "русскоае", 22, 3.9f, 1},
            {4, "David Williams","fadsfdsfs", 23, 3.7f, 2}
    };

    // Описание столбцов таблицы
    TableColumn columns[] = {
            {"id", offsetof(Product, id), formatSizeT, 0},
            {"name", offsetof(Product, name), formatString, 0},
            {"description", offsetof(Product, description), formatString, 0},
            {"price", offsetof(Product, price), formatFloat, 0},
            {"amount", offsetof(Product, amount), formatFloat, 0},
            {"category_id", offsetof(Product, category_id), formatSizeT, 0}

    };

    // Выводим таблицу
    printTable(products, 4, columns, 5);
    
    
//    free(products);
    return 0;
}
