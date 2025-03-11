//
// Created by mazin on 11.03.2025.
//

#ifndef DATABASE_READWRITEFILE_H
#define DATABASE_READWRITEFILE_H

#include "../database/productList.h"
#include "../output/tableColumn.h"

void writeHeader(const char* filename, ProductList *product, TableColumn* columns, char separator);

// Функция для преобразования int в строку
void intToString(const void* data, char* buffer, size_t size);


// Функция для преобразования float в строку
void floatToString(const void* data, char* buffer, size_t size);


// Функция для преобразования double в строку
void doubleToString(const void* data, char* buffer, size_t size);


// Функция для преобразования строки в строку (просто копирование)
void stringToString(const void* data, char* buffer, size_t size);


// Полиморфная функция для записи данных
void myFputs(FILE* file, const void* data, void (*toString)(const void*, char*, size_t), char separator);

void writeData(const char* filename, ProductList *products, char separator);

void saveTable(const char * filename, ProductList *products, TableColumn *columns, char separator);


#endif //DATABASE_READWRITEFILE_H
