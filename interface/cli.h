//
// Created by mazin on 12.03.2025.
//

#ifndef DATABASE_CLI_H
#define DATABASE_CLI_H

#include <stdio.h>
#include "../lexicon/lexicon.h"
#include "../service/getLine.h"
#include "../database/products.h"
#include "../database/productList.h"
#include "../database/tableColumn.h"
#include "../output/outputConsoleDB.h"
#include "../interactionFile/writeFile.h"
#include "../interactionFile/readFile.h"
#include "../sorted/sortedByField.h"
#include "../service/getLine.h"


typedef enum {
    SUCCESS = 1,
    EXIT = 2,
    OTHER_COMMAND = 3,
    ERROR = 0,
} CODE_HANDLER;

void printINFO();

void printHELP();

bool chooseAct(char* act);

CODE_HANDLER handlerMessage(ProductList *productList, TableColumnList *columnList,
                    char * message, IdGenerator *productIdGenerator, char* filename);

void setFileName(char *filename, size_t filenameSize);


#endif //DATABASE_CLI_H
