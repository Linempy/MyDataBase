//
// Created by mazin on 11.03.2025.
//
#include "readFile.h"

char* readLine(FILE* file) {
    size_t currSize = 32;
    size_t len = 0;
    char *buffer = malloc(currSize * sizeof(char));
    if (!buffer) {
        perror("Ошибка выделения памяти.");
        return NULL;
    }

    while (fgets(buffer + len, currSize - len, file)) {
        len = strlen(buffer);
        if (len > 0 && (buffer[len - 1] == '\n' || feof(file))) {
            if (buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }
            return buffer;
        }

        // Увеличиваем буфер
        currSize *= 2;
        char *newBuffer = realloc(buffer, currSize);
        if (!newBuffer) {
            free(buffer);
            perror("Ошибка выделения памяти.");
            return NULL;
        }
        buffer = newBuffer;
    }


    if (feof(file)) {
        if (len > 0) {
            return buffer;
        } else {
            free(buffer);
            perror("Пустая строка в конце файла");
            return NULL;
        }
    } else {
        free(buffer);
        perror("Ошибка чтения файла");
        return NULL;
    }
}



TableColumnList readHeader(char * filename, char delimiter, size_t defaultCapacity){
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла");
        fclose(file);
        return (TableColumnList) {NULL, 0,0};
    }

    char* line = readLine(file);
    if (!line){
        perror("Ошибка чтения файла");
        fclose(file);
        return (TableColumnList) {NULL, 0,0};
    }

    size_t tokenCount = 6;
    char **columns = splitString(line, delimiter, &tokenCount);
    if (!columns) {
        perror("Ошибка чтения заголовка файла");
        free(line);
        fclose(file);
        return (TableColumnList) {NULL, 0,0};
    }

    TableColumnList tableColumns = createTableColumnList(defaultCapacity);
    addTableColumn(&tableColumns, strdup(columns[0]),
                   offsetof(Product, id), formatSizeT, 0);
    addTableColumn(&tableColumns, strdup(columns[1]),
                   offsetof(Product, name), formatString, 0);
    addTableColumn(&tableColumns, strdup(columns[2]),
                   offsetof(Product, description), formatString, 0);
    addTableColumn(&tableColumns, strdup(columns[3]),
                   offsetof(Product, price), formatFloat, 0);
    addTableColumn(&tableColumns, strdup(columns[4]),
                   offsetof(Product, amount), formatFloat, 0);
    addTableColumn(&tableColumns, strdup(columns[5]),
                   offsetof(Product, category_id), formatSizeT, 0);

    free(line);
    freeArrayData(columns, tokenCount);
    fclose(file);


    return tableColumns;
}


bool parseSizeT(const char *str, size_t *result) {
    char *endPtr;
    errno = 0;
    size_t value = strtoull(str, &endPtr, 10);

    if (errno == ERANGE || *endPtr != '\0') {
        return 0;
    }
    *result = value;
    return 1;
}

bool parseFloat(const char *str, float* result) {
    char *endPtr;
    errno = 0;
    float value = strtof(str, &endPtr);

    if (errno == ERANGE || *endPtr != '\0') {
        return 0;
    }

    *result = value;
    return 1;
}


void freeArrayData(char** data, size_t count) {
    if (data) {
        for (size_t i = 0; i < count; i++) {
            free(data[i]);
        }
        free(data);
    }
}

ProductList readData(char * filename, char delimiter, ProductList *products,
                     IdGenerator *idGenerator){
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытии файла");
        return (ProductList) {NULL, 0, 0};
    }

    char* line = readLine(file); // Пропускаем первую строку
    size_t tokenCount = 6;
    while ((line=readLine(file)) != NULL) {
        char **data = splitString(line, delimiter, &tokenCount);
        if (tokenCount != 6) {
            fprintf(stderr, "Ошибка: некорректное количество полей в строке.\n");
            free(line);
            line = NULL;
            freeArrayData(data, tokenCount);
            continue;
        }

        size_t id, category_id;
        float price, amount;

        if (!parseSizeT(data[0], &id)) {
            fprintf(stderr, "Ошибка: некорректный ID.\n");
            free(line);
            line = NULL;
            freeArrayData(data, tokenCount);
            continue;
        }
        if (!parseFloat(data[3], &price)) {
            fprintf(stderr, "Ошибка: некорректная цена.\n");
            free(line);
            line = NULL;
            freeArrayData(data, tokenCount);
            continue;
        }
        if (!parseFloat(data[4], &amount)) {
            fprintf(stderr, "Ошибка: некорректное количество.\n");
            free(line);
            line = NULL;
            freeArrayData(data, tokenCount);
            continue;
        }
        if (!parseSizeT(data[5], &category_id)) {
            fprintf(stderr, "Ошибка: некорректный ID категории.\n");
            free(line);
            line = NULL;
            freeArrayData(data, tokenCount);
            continue;
        }

        Product *product = fillProductByIdGenerator(idGenerator, data[1],
                                                    data[2], price, amount, category_id);
        addProduct(products, product);

        free(line);
        line = NULL;
        freeArrayData(data, tokenCount);
    }

    fclose(file);

    return *products;
}


bool loadTable(ProductList *products,TableColumnList *columns,
              char * filename, char delimiter, IdGenerator *idGenerator, size_t defaultSizeProdList) {

    if (!products || !columns || !filename) {
        fprintf(stderr, "Ошибка: неверные аргументы.\n");
        return false;
    }

    TableColumnList columnList = readHeader(filename, delimiter, 6);
    if (columnList.columns == NULL) {
        fprintf(stderr, "Ошибка чтения заголовка таблицы.\n");
        return false;
    }

    ProductList productList = readData(filename, delimiter, products, idGenerator);
    if (isEmptyProduct(&productList) || productList.products == NULL) {
        fprintf(stderr, "Ошибка чтения данных таблицы.\n");

        freeTableColumnList(&columnList);

        if(!isEmptyProduct(&productList)) {
            freeProductList(&productList);
        }

        return false;
    }

    *columns = columnList;
    *products = productList;

    return true;

}
