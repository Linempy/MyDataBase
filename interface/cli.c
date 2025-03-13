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


CODE_HANDLER handlerMessage(ProductList *products, TableColumnList *columns,
                            char * message, IdGenerator *productIdGenerator) {
    if (!products || !columns || !message || !productIdGenerator) {
        fprintf(stderr, "%s", INCORRECT_ARGUMENTS);
        return ERROR;
    }

    if (strcmp(message, ADD_PRODUCT) == 0) {
        Product *product = inputDataProduct(productIdGenerator);
        if(!addProduct(products, product)){
            fprintf(stderr, "%s", ERROR_ADD_PRODUCT);
            return ERROR;
        }
        printf("%s", PRODUCT_WAS_ADDED);
        return SUCCESS;
    }

    if (strcmp(message, DELETE_PRODUCT) == 0) {
        size_t id;
        if (!inputIdByProduct(&id)){
            ///подумать насчет возврата ошибки
            return ERROR;
        }
        removeProduct(products, id, 4);
        return SUCCESS;
    }

    if (strcmp(message, PRINT_TABLE) == 0) {
        printTable(products, columns->columns, columns->count);
        return SUCCESS;
    }

    if (strcmp(message, EXIT_FROM_APP) == 0) {
        return EXIT;
    }

    printf("%s", OTHER_MESSAGE);
    return OTHER_COMMAND;
}
