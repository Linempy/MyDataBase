#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "database/products.h"
#include "output/outputConsoleDB.h"
#include "output/tableColumn.h"
#include "database/productList.h"


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

    ProductList products = createProductList(2);
    Product prd = {1, "Alice Johnson", "dsafdsfsf", 20, 3.8f, 1};
    addProduct(&products, &prd);
    addProduct(&products, &(Product) {2,
                                     "Bob Smith with a very long name that exceeds the limit",
                                     "fdasfsdf",21, 3.5f, 2});
//            {2, "Bob Smith with a very long name that exceeds the limit",
//             "fdasfsdf",21, 3.5f, 2},
//            {3, "Charlie Brown", "dfsfd", 22, 3.9f, 1},
//            {4, "David Williams","fadsfdsfs", 23, 3.7f, 2}
//    };

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
    printTable(&products, columns, 5);
    removeProduct(&products, 0, defaultSize);
    printTable(&products, columns, 5);

//    free(products);
    return 0;
}
