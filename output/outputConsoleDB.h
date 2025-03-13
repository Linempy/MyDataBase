//
// Created by mazin on 09.03.2025.
//

#ifndef DATABASE_OUTPUTCONSOLEDB_H
#define DATABASE_OUTPUTCONSOLEDB_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../database/tableColumn.h"
#include "../database/products.h"
#include "../database/productList.h"
#include "formatField.h"


void calculateColumnWidths(const ProductList *products, TableColumn* columns, size_t numColumns);


void printTableHeaders(TableColumn* columns, size_t numColumns);


void printTableSeparator(TableColumn* columns, size_t numColumns);


void printTableData(const ProductList *products, TableColumn* columns, size_t numColumns);


void printTable(const ProductList *products, TableColumn* columns, size_t numColumns);



#endif //DATABASE_OUTPUTCONSOLEDB_H
