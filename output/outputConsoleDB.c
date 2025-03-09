//
// Created by mazin on 09.03.2025.
//
#include "outputConsoleDB.h"
#include "tableColumn.h"
#include "../service/visualWidth.h"
#include "../database/products.h"
#include "../service/visualWidth.h"


void formatInt(char* dest, size_t destSize, const void* field) {
    snprintf(dest, destSize, "%d", *(const int*)field);
}


void formatSizeT(char* dest, size_t destSize, const void* field) {
    snprintf(dest, destSize, "%zu", *(const size_t*)field);
}


void formatFloat(char* dest, size_t destSize, const void* field) {
    snprintf(dest, destSize, "%.2f", *(const float*)field);
}


void formatString(char* dest, size_t destSize, const void* field) {
    snprintf(dest, destSize, "%s", (const char*)field);
}


void truncateAndPadString(char* dest, const char* src, size_t width) {
    size_t srcLen = visualWidth(src);
    if (srcLen > width - 3) {
        strncpy(dest, src, width - 3);
        dest[width - 3] = '\0';
        strcat(dest, "...");
    } else {
        strcpy(dest, src);
    }

    size_t destLen = visualWidth(dest);
    if (destLen < width) {
        memset(dest + destLen, ' ', width - destLen);
        dest[width] = '\0';
    }
}


// Функция для вывода таблицы без внешних границ
void printTable(const Product* products, size_t count, TableColumn* columns, size_t numColumns) {
    // Вычисляем максимальную ширину для каждого столбца
    for (TableColumn *currColumn = columns, *end = columns + numColumns; currColumn < end; currColumn++) {
        currColumn->width = visualWidth(currColumn->header);
    }

    for (const Product *currProduct = products, *endProduct = products + count;
         currProduct < endProduct; currProduct++) {
        for (TableColumn *currColumn = columns, *endColumn = columns + numColumns;
             currColumn < endColumn; currColumn++) {

            char buffer[256];
            currColumn->format(buffer,
                               sizeof(buffer),
                               (const char*)(currProduct) + currColumn->offset);
            size_t len = visualWidth(buffer);
            if (len > currColumn->width) {
                currColumn->width = len;
            }
        }
    }

    // Выводим заголовки
    for (TableColumn *currColumn = columns, *end = columns + numColumns; currColumn < end; currColumn++) {
        if (currColumn == columns) printf(" %-*s ", currColumn->width, currColumn->header);
        else printf("| %-*s ", currColumn->width, currColumn->header);
    }
    printf("\n");

    for (const TableColumn *currColumn = columns, *end = columns + numColumns; currColumn < end; currColumn++) {
        if (currColumn == columns) printf("-");
        else printf("+-");

        for (int i = 0; i < currColumn->width; i++) {
            printf("-");
        }
        printf("-");
    }
    printf("\n");

    for (const Product *currProduct = products, *endProduct = products + count;
         currProduct < endProduct; currProduct++) {
        for (const TableColumn *currColumn = columns, *endColumn = columns + numColumns;
             currColumn < endColumn; currColumn++) {

            char buffer[256]; // Буфер для форматирования значения
            currColumn->format(
                    buffer,
                    sizeof(buffer),
                    (const char*)(currProduct) + currColumn->offset);
            if (currColumn == columns) printf(" %-*s ", currColumn->width, buffer);
            else printf("| %-*s ", currColumn->width, buffer);
        }
        printf("\n");
    }
}
