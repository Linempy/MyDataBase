#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "database/products.h"
#include "output/outputConsoleDB.h"
#include "output/tableColumn.h"
#include "database/productList.h"
#include "sorted/sortedByField.h"
#include "interactionFile/writeFile.h"
#include "service/splitString.h"
#include "interactionFile/readFile.h"



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
    size_t defaultSizeProdList = 2;
//
//
//    ProductList products = createProductList(2);
//    Product prd = {1, "Alice Johnson", "dsafdsfsf", 20, 3.8f, 1};
//    addProduct(&products, &prd);
//    addProduct(&products, &(Product) {2,
//                                      "Bob Smith with a very long name that exceeds the limit",
//                                      "fdasfsdf",21, 3.5f, 2});
//    addProduct(&products, &(Product) {3, "Charlie Brown",
//                                      "dfsfd", 22, 3.9f, 1});
//    addProduct(&products, &(Product) {4, "David Williams",
//                                      "fadsfdsfs", 23, 3.7f, 2});
//
//    // Пример
//    size_t defaultCapacityTableColumn = 6;
//    TableColumnList list = createTableColumnList(defaultCapacityTableColumn);
//
//    addTableColumn(&list, "id", offsetof(Product, id), formatSizeT, 0);
//    addTableColumn(&list, "name", offsetof(Product, name), formatString, 0);
//    addTableColumn(&list, "description", offsetof(Product, description), formatString, 0);
//    addTableColumn(&list, "price", offsetof(Product, price), formatFloat, 0);
//    addTableColumn(&list, "amount", offsetof(Product, amount), formatFloat, 0);
//    addTableColumn(&list, "category_id", offsetof(Product, category_id), formatSizeT, 0);


    TableColumnList list = readHeader("example.txt", ';', 6);
    ProductList products = readData("example.txt", ';', defaultSizeProdList);

    // Выводим таблицу
    myQsort(products.products, products.length, sizeof(Product), comparePrice);
    printTable(&products, list.columns, 6);
    saveTable("example.txt", &products, list.columns, ';');


    freeProductList(&products);
    freeTableColumnList(&list);
    return 0;
}
