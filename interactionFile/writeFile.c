//
// Created by mazin on 11.03.2025.
//
#include "writeFile.h"


bool writeHeader(const char* filename, TableColumn* columns, char delimiter) {
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
    return true;
}


bool writeData(const char* filename, ProductList *products, char delimiter) {
    FILE *file = fopen(filename, "a");
    if (!file) {
        printf("Ошибка в открытии файла");
        return false;
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
            return false;
        }
    }

    fclose(file);
    return true;
}

bool saveTable(const char * filename, ProductList *products, TableColumn *columns, char delimiter) {
    if (!filename) {
        fprintf(stderr, "Ошибка в названии файла");
        return false;
    }

    if (!products || !columns) {
        printf("Таблица пуста");
        return false;
    }

    if(!writeHeader(filename, columns, delimiter)){
        sprintf(stderr, "%s", "Ошибка записи заголовка таблицы");
        return false;
    }

    if(!writeData(filename, products, delimiter)){
        sprintf(stderr, "%s", "Ошибка записи данных таблицы");
        return false;
    }

    printf("Файл \"%s\" успешно сохранен\n", filename);

    return true;
}
