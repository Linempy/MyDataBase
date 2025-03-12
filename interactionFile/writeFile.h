//
// Created by mazin on 11.03.2025.
//

#ifndef DATABASE_WRITEFILE_H
#define DATABASE_WRITEFILE_H

#include "../database/productList.h"
#include "../output/tableColumn.h"

void writeHeader(const char* filename, ProductList *product, TableColumn* columns, char delimiter);

// Функция для преобразования int в строку
void intToString(const void* data, char* buffer, size_t size);


// Функция для преобразования float в строку
void floatToString(const void* data, char* buffer, size_t size);


// Функция для преобразования double в строку
void doubleToString(const void* data, char* buffer, size_t size);


// Функция для преобразования строки в строку (просто копирование)
void stringToString(const void* data, char* buffer, size_t size);


// Полиморфная функция для записи данных
void myFputs(FILE* file, const void* data, void (*toString)(const void*, char*, size_t), char delimiter);

void writeData(const char* filename, ProductList *products, char delimiter);

void saveTable(const char * filename, ProductList *products, TableColumn *columns, char delimiter);

//FILE* saveOpen(const char* filename, const char* mode);

#endif //DATABASE_WRITEFILE_H
