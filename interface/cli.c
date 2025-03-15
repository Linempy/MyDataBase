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

bool setFileName(char *filename, size_t filenameSize){
    if (!filename || filenameSize == 0) {
        fprintf(stderr, "%s", INCORRECT_ARGUMENTS);
        return false;
    }

    char prompt[86];
    sprintf(prompt, "Введите название таблицы (макс. %zu символов): ", filenameSize-5);
    if (!inputString(filename, (int) filenameSize,
                     prompt)) {
        fprintf(stderr, "Ошибка ввода названия файла\n");
        return false;
    }

    if (strlen(filename) + 4 >= filenameSize) {
        fprintf(stderr, "Ошибка: название файла слишком длинное\n");
        return false;
    }

    strcat(filename, ".txt");
    return true;
}


CODE_HANDLER handlerMessage(ProductList *products, TableColumnList *columns,
                            char * message, IdGenerator *productIdGenerator, char* filename) {
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

    if(strcmp(message, SAVE_TABLE) == 0) {
        char saveFileName[64];
        if(!setFileName(saveFileName, sizeof(saveFileName))) {
            return ERROR;
        }

        if(!saveTable(saveFileName, products, columns->columns, DELIMITER)){
            return ERROR;
        }
        return SUCCESS;
    }

    if (strcmp(message, LOAD_TABLE) == 0) {
        char loadFileName[64];
        setFileName(loadFileName, sizeof(loadFileName));
        if (!loadTable(products, columns, loadFileName, DELIMITER,
                       productIdGenerator, 6)) {
            fprintf(stderr, "%s", ERROR_LOAD_TABLE);
            return ERROR;
        }
        return SUCCESS;
    }

    ///Перенести часть логики в отдельную функцию
    if (strcmp(message, SORT_TABLE) == 0) {
        int typeSort;
        int numberField;
        if(!inputNumber(&typeSort, "%d", TYPE_SORT_MESSAGE, INCORRECT_ARGUMENTS) ||
           !inputNumber(&numberField, "%d",CHOOSE_FIELD_SORT, INCORRECT_ARGUMENTS)){
            fprintf(stderr, "%s", INCORRECT_ARGUMENTS);
            return ERROR;
        }

        if (typeSort < 1 || typeSort > 2) {
            fprintf(stderr, "%s", INCORRECT_ARGUMENTS);
            return ERROR;
        }

        int order = typeSort == 1 ? 1 : -1;
        if (numberField < 0 || numberField > NUM_FIELDS){
                fprintf(stderr, "%s", INCORRECT_ARGUMENTS);
        }
        myQsort(products->products, products->length, sizeof(Product),
                comparators[(FieldType) numberField - 1], order);
        printf("%s", SUCCESS_SORT);

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
