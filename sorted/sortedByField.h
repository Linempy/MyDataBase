//
// Created by mazin on 10.03.2025.
//

#ifndef DATABASE_SORTEDBYFIELD_H
#define DATABASE_SORTEDBYFIELD_H

#include <string.h>
#include "../database/productList.h"

typedef enum {
    FIELD_ID,
    FIELD_NAME,
    FIELD_DESCRIPTION,
    FIELD_PRICE,
    FIELD_AMOUNT,
    FIELD_CATEGORY_ID,
    NUM_FIELDS
} FieldType;



typedef struct {
    int (*comparator)(const void*, const void*, int);
    int order;
} ComparatorWrapper;

/*
 * Возвращаемое значение:
 * Отрицательное число, если первый аргумент меньше второго.
 * Ноль, если аргументы равны.
 * Положительное число, если первый аргумент больше второго.
 * */
typedef int (*comparator)(const void *, const void *, int);



int compareId(const void* a, const void* b, int order);


int comparePrice(const void* a, const void* b, int order);


int compareAmount(const void* a, const void* b, int order);


int compareName(const void* a, const void* b, int order);


int compareDescription(const void* a, const void* b, int order);


int compareCategoryId(const void* a, const void* b, int order);


extern int (*comparators[])(const void*, const void*, int);

/*void* base: Указатель на начало массива.
size_t low: Начальный индекс подмассива.
size_t high: Конечный индекс подмассива.
size_t size: Размер одного элемента в байтах.
int (*compar)(const void*, const void*): Указатель на функцию сравнения.
 */
size_t partition(void* base, size_t low, size_t high, size_t size,
                 int (*comparator)(const void*, const void*, void*), void* context);


/*void* base: Указатель на начало массива.
size_t nmemb: Количество элементов в массиве.
size_t size: Размер одного элемента в байтах.
int (*compar)(const void*, const void*): Указатель на функцию сравнения.
 */
void quickSort(void* base, size_t low, size_t high, size_t size,
               int (*comparator)(const void*, const void*, void*), void* context);


void myQsort(void* base, size_t nmemb, size_t size, int (*comparator)(const void*, const void*, int), int order);

#endif //DATABASE_SORTEDBYFIELD_H
