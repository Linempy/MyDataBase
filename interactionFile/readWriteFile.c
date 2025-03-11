//
// Created by mazin on 11.03.2025.
//
#include "readWriteFile.h"

// Функция для преобразования int в строку
void sizeT_ToString(const void* data, char* buffer, size_t size) {
    snprintf(buffer, size, "%zu", *(size_t*)data);
}


// Функция для преобразования float в строку
void floatToString(const void* data, char* buffer, size_t size) {
    snprintf(buffer, size, "%.2f", *(float*)data);
}


// Функция для преобразования double в строку
void doubleToString(const void* data, char* buffer, size_t size) {
    snprintf(buffer, size, "%.2lf", *(double*)data);
}


// Функция для преобразования строки в строку (просто копирование)
void stringToString(const void* data, char* buffer, size_t size) {
    snprintf(buffer, size, "%s", (const char*)data);
}


// Полиморфная функция для записи данных
void myFputs(FILE* file, const void* data, void (*toString)(const void*, char*, size_t), char separator) {
    char buffer[255]; // Буфер для преобразования данных в строку

    // Преобразуем данные в строку
    toString(data, buffer, sizeof(buffer));

    if (fputs(buffer, file) == EOF) {
        printf("Ошибка записи файла\n");
        return;
    }

    if (fputc(separator, file) == EOF) {
        printf("Ошибка записи файла\n");
        return;
    }
}


void writeHeader(const char* filename, ProductList *product, TableColumn* columns, char separator) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка в открытии файла");
        return;
    }

    //Заголовки
    for (TableColumn *currColumn = columns, *endColumn = columns + 5;
        currColumn < endColumn; currColumn++) {

        myFputs(file, currColumn->header, stringToString, ';');

    }

    if(fputc('\n', file) == EOF) {
        printf("Ошибка записи файла\n");
        fclose(file);
        return;
    }

    fclose(file);
}


void writeData(const char* filename, ProductList *products, char separator) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        printf("Ошибка в открытии файла");
        return;
    }

    //Заголовки
    for (Product *currProduct = products->products, *endProduct = products->products + products->length;
         currProduct < endProduct; currProduct++) {

        myFputs(file, &currProduct->id, sizeT_ToString, ';');
        myFputs(file, currProduct->name, stringToString, ';');
        myFputs(file, currProduct->description, stringToString, ';');
        myFputs(file, &currProduct->price, floatToString, ';');
        myFputs(file, &currProduct->amount, floatToString, ';');
        myFputs(file, &currProduct->category_id, sizeT_ToString, ';');

        if(fputc('\n', file) == EOF) {
            printf("Ошибка записи файла\n");
            fclose(file);
            return;
        }

    }

    fclose(file);
}

void saveTable(const char * filename, ProductList *products, TableColumn *columns, char separator) {
    writeHeader(filename, products, columns, separator);

    writeData(filename, products, separator);
    printf("Файл \"%s\" успешно сохранен\n", filename);
}