#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "database/products.h"
#include "output/outputConsoleDB.h"
#include "database/tableColumn.h"
#include "database/productList.h"
#include "sorted/sortedByField.h"
#include "interactionFile/writeFile.h"
#include "service/splitString.h"
#include "interactionFile/readFile.h"
#include "interface/cli.h"
#include "lexicon/lexicon.h"


int main(void) {

    system("chcp 65001");
    size_t defaultSizeProdList = 2;
    bool processWork = true;
    ProductList products = createProductList(4);
    IdGenerator productIdGenerator = {1};
    TableColumnList columns = createTableColumnList(6);
    addDefaultProductColumns(&columns);


    printf("%s", HELLO_MESSAGE);
    printf("%s", INFO_OF_APP);

    while (processWork) {
        char message[255];
        if(chooseAct(message)) {
            handlerMessage(&products, &columns, message, &productIdGenerator);
        } else return 0;
    }

//    TableColumnList list = readHeader("example.txt", ';', 6);
//    ProductList products = readData("example.txt", ';', defaultSizeProdList);

    // Выводим таблицу
//    myQsort(products.products, products.length, sizeof(Product), comparePrice);
//    printTable(&products, list.columns, 6);
//    saveTable("example.txt", &products, list.columns, ';');


    freeProductList(&products);
    freeTableColumnList(&columns);

    return 0;
}
