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


void printINFO();

void printHELP();

bool chooseAct(char* act);

bool handlerMessage(ProductList *productList, TableColumnList *columnList,
                    char * message, IdGenerator *productIdGenerator);



#endif //DATABASE_CLI_H
