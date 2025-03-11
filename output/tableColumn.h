//
// Created by mazin on 09.03.2025.
//

#ifndef DATABASE_TABLECOLUMN_H
#define DATABASE_TABLECOLUMN_H

#include <stddef.h>
#include <stdlib.h>
#include "formatField.h"

typedef struct {
    const char* header;
    size_t offset;
    FormatField format;
    size_t width;
    size_t count;
} TableColumn;


typedef struct {
    TableColumn *columns;
    size_t count;
    size_t capacity;
} TableColumnList;

TableColumnList createTableColumnList(size_t initialCapacity);
void addTableColumn(TableColumnList *list, const char *header, size_t offset, FormatField format, size_t width);

void freeTableColumnList(TableColumnList *list);




#endif //DATABASE_TABLECOLUMN_H
