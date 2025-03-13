//
// Created by mazin on 11.03.2025.
//
#include "writeFile.h"

//// Функция для преобразования int в строку
//void sizeT_ToString(const void* data, char* buffer, size_t size) {
//    snprintf(buffer, size, "%zu", *(size_t*)data);
//}
//
//
//// Функция для преобразования float в строку
//void floatToString(const void* data, char* buffer, size_t size) {
//    snprintf(buffer, size, "%.2f", *(float*)data);
//}
//
//
//// Функция для преобразования double в строку
//void doubleToString(const void* data, char* buffer, size_t size) {
//    snprintf(buffer, size, "%.2lf", *(double*)data);
//}
//
//
//// Функция для преобразования строки в строку (просто копирование)
//void stringToString(const void* data, char* buffer, size_t size) {
//    snprintf(buffer, size, "%s", (const char*)data);
//}


// Полиморфная функция для записи данных
//void myFputs(FILE* file, const void* data, void (*toString)(const void*, char*, size_t), char separator) {
//    char buffer[255]; // Буфер для преобразования данных в строку
//
//    // Преобразуем данные в строку
//    toString(data, buffer, sizeof(buffer));
//
//    if (fputs(buffer, file) == EOF) {
//        printf("Ошибка записи файла\n");
//        return;
//    }
//
//    if (fputc(separator, file) == EOF) {
//        printf("Ошибка записи файла\n");
//        return;
//    }
//}


bool writeHeader(const char* filename, TableColumn* columns, char delimiter) {
    printf("%shbhjb   ", filename);
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка в открытии файла");
        return false;
    }

    //Заголовки
    for (TableColumn *currColumn = columns, *endColumn = columns + 6;
        currColumn < endColumn; currColumn++) {
        if(endColumn - currColumn > 1) fprintf(file, "%s%c", currColumn->header, delimiter);
        else fprintf(file, "%s", currColumn->header);
    }

    if(fputc('\n', file) == EOF) {
        printf("Ошибка записи файла\n");
        fclose(file);
        return false;
    }

    fclose(file);
}


void writeData(const char* filename, ProductList *products, char delimiter) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        printf("Ошибка в открытии файла");
        return;
    }

    for (Product *currProduct = products->products, *endProduct = products->products + products->length;
         currProduct < endProduct; currProduct++) {

        fprintf(file, "%zu%c", currProduct->id, delimiter);
        fprintf(file, "%s%c", currProduct->name, delimiter);
        fprintf(file, "%s%c", currProduct->description, delimiter);
        fprintf(file, "%.2f%c", currProduct->price, delimiter);
        fprintf(file, "%.2f%c", currProduct->amount, delimiter);
        fprintf(file, "%zu", currProduct->category_id);

        if(fputc('\n', file) == EOF) {
            printf("Ошибка записи файла\n");
            fclose(file);
            return;
        }
    }

    fclose(file);
}

void saveTable(const char * filename, ProductList *products, TableColumn *columns, char delimiter) {
    if (!filename) {
        fprintf(stderr, "Ошибка в названии файла");
        return;
    }

    if (!products || !columns) {
        printf("Таблица пуста");
        return;
    }

    writeHeader(filename, columns, delimiter);

    writeData(filename, products, delimiter);
    printf("Файл \"%s\" успешно сохранен\n", filename);
}
