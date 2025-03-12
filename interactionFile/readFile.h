//
// Created by mazin on 11.03.2025.
//

#ifndef DATABASE_READFILE_H
#define DATABASE_READFILE_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../service/splitString.h"
#include "../database/productList.h"
#include "../database/products.h"
#include "../database/tableColumn.h"
#include "../output/outputConsoleDB.h"


char* readLine(FILE* file);

TableColumnList readHeader(char * filename, char delimiter, size_t defaultCapacity);

size_t parseSizeT(const char *str, size_t *result);

float parseFloat(const char *str, float* result);

void freeArrayData(char** data, size_t tokenCount);

ProductList readData(char * filename, char delimiter, size_t defaultSizeProdList);

#endif //DATABASE_READFILE_H
