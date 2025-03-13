//
// Created by mazin on 09.03.2025.
//
#include "outputConsoleDB.h"



void formatSizeT(char* dest, size_t destSize, const void* field) {
    snprintf(dest, destSize, "%zu", *(const size_t*)field);
}


void formatFloat(char* dest, size_t destSize, const void* field) {
    snprintf(dest, destSize, "%.2f", *(const float*)field);
}


void formatString(char* dest, size_t destSize, const void* field) {
    snprintf(dest, destSize, "%s", (const char*)field);
}


// Вычисление ширины столбцов
void calculateColumnWidths(const ProductList *products, TableColumn* columns, size_t numColumns) {
    for (TableColumn *currColumn = columns, *end = columns + numColumns; currColumn < end; currColumn++) {
        currColumn->width = strlen(currColumn->header);
    }

    for (size_t i = 0; i < products->length; i++) {
        for (TableColumn *currColumn = columns, *endColumn = columns + numColumns;
        currColumn < endColumn; currColumn++) {

            char buffer[256];
            currColumn->format(buffer, sizeof(buffer),
                               (const char*)(&products->products[i]) + currColumn->offset);
            size_t len = strlen(buffer);
            if (len > currColumn->width) {
                currColumn->width = len;
            }
        }
    }
}


void printTableHeaders(TableColumn* columns, size_t numColumns) {
    printf("\n");
    for (TableColumn *currColumn = columns, *end = columns + numColumns; currColumn < end; currColumn++) {
        if (currColumn == columns) printf(" %-*s ", currColumn->width, currColumn->header);
        else printf("| %-*s ", currColumn->width, currColumn->header);
    }
    printf("\n");
}


// Вывод разделительной линии
void printTableSeparator(TableColumn* columns, size_t numColumns) {
    for (const TableColumn *currColumn = columns, *end = columns + numColumns; currColumn < end; currColumn++) {
        if (currColumn == columns) printf("-");
        else printf("+-");

        for (int i = 0; i < currColumn->width; i++) {
            printf("-");
        }
        printf("-");
    }
    printf("\n");
}


void printTableData(const ProductList* products, TableColumn* columns, size_t numColumns) {
    for (size_t i = 0; i < products->length; i++) {
        for (const TableColumn *currColumn = columns, *endColumn = columns + numColumns;
        currColumn < endColumn; currColumn++) {

            char buffer[256];
            currColumn->format(buffer,
                               sizeof(buffer),
                               (const char*)(&products->products[i]) + currColumn->offset);
            if (currColumn == columns) printf(" %-*s ", currColumn->width, buffer);
            else printf("| %-*s ", currColumn->width, buffer);
        }
        printf("\n");
    }
}


// Основная функция для вывода таблицы
void printTable(const ProductList *products, TableColumn* columns, size_t numColumns) {
    if (!products || !columns || numColumns == 0) {
        fprintf(stderr, "Invalid input parameters.\n");
        return;
    } else if(isEmptyProduct(products) || products->length == 0) {
        printf("%s", "\nТаблица пуста\n");
        return ;
    }

    // Вычисляем ширину столбцов
    calculateColumnWidths(products, columns, numColumns);

    // Выводим заголовки
    printTableHeaders(columns, numColumns);

    // Выводим разделительную линию
    printTableSeparator(columns, numColumns);

    // Выводим данные
    printTableData(products, columns, numColumns);
    printf("\n");
}

