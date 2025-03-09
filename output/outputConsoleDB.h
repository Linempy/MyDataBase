//
// Created by mazin on 09.03.2025.
//

#ifndef DATABASE_OUTPUTCONSOLEDB_H
#define DATABASE_OUTPUTCONSOLEDB_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tableColumn.h"
#include "../database/products.h"


void formatFloat(char* dest, size_t destSize, const void* field);


void formatString(char* dest, size_t destSize, const void* field);


void formatSizeT(char* dest, size_t destSize, const void* field);


void truncateAndPadString(char* dest, const char* src, size_t width);


void printTable(const Product* products, size_t count, TableColumn* columns, size_t numColumns);


#endif //DATABASE_OUTPUTCONSOLEDB_H
