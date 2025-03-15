//
// Created by mazin on 11.03.2025.
//
#include "tableColumn.h"

TableColumnList createTableColumnList(size_t initialCapacity) {
    TableColumnList list;
    list.columns = malloc(initialCapacity * sizeof(TableColumn));
    if (!list.columns) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    list.count = 0;
    list.capacity = initialCapacity;
    return list;
}

void addTableColumn(TableColumnList *list, const char *header, size_t offset, FormatField format, size_t width) {
    if (list->count >= list->capacity) {
        size_t newCapacity = list->capacity * 2;
        TableColumn *newColumns = realloc(list->columns, newCapacity * sizeof(TableColumn));
        if (!newColumns) {
            perror("Ошибка выделения памяти");
            exit(EXIT_FAILURE);
        }
        list->columns = newColumns;
        list->capacity = newCapacity;
    }

    // Добавляем новый столбец
    list->columns[list->count].header = header;
    list->columns[list->count].offset = offset;
    list->columns[list->count].format = format;
    list->columns[list->count].width = width;
    list->count++;
}


void freeTableColumnList(TableColumnList *list) {
    if (list) {
        if (list->columns) {
            free(list->columns);
            list->columns = NULL;
        }
        list->count = 0;
    }
}


void addDefaultProductColumns(TableColumnList *list) {
    addTableColumn(list, "id", offsetof(Product, id), formatSizeT, 0);
    addTableColumn(list, "name", offsetof(Product, name), formatString, 0);
    addTableColumn(list, "description", offsetof(Product, description), formatString, 0);
    addTableColumn(list, "price", offsetof(Product, price), formatFloat, 0);
    addTableColumn(list, "amount", offsetof(Product, amount), formatFloat, 0);
    addTableColumn(list, "category_id", offsetof(Product, category_id), formatSizeT, 0);
}
