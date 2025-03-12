//
// Created by mazin on 12.03.2025.
//
#include "cli.h"


void printINFO() {
    printf("%s", INFO_OF_APP);
}

void printHELP() {
    printf("%s", HELP_MESSAGE);
}

bool chooseAct(char * act){
    if(!inputString(act, 30*sizeof(char), CHOOSE_ACT)){
        printf("%s", ERROR_CHOOSE_ACT);
        return false;
    }

    return true;
}


bool handlerMessage(ProductList *products, TableColumnList *columns, char * message, IdGenerator *productIdGenerator) {
    if (strcmp(message, ADD_PRODUCT) == 0) {
        Product *product = inputDataProduct(productIdGenerator);
        if(!addProduct(products, product)){
            printf("Ошбика добавления продукта");
        };
        printf("%s", PRODUCT_WAS_ADDED);
    } else if (strcmp(message, DELETE_PRODUCT) == 0) {
        return 1;
    } else if (strcmp(message, PRINT_TABLE) == 0) {
        printTable(products, columns->columns, columns->count);
    }
    else {
        printf("%s", OTHER_MESSAGE);
        return 0;
    }
    return 1;
}
