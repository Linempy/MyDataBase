//
// Created by mazin on 10.03.2025.
//

#ifndef DATABASE_SORTEDBYFIELD_H
#define DATABASE_SORTEDBYFIELD_H

#include <string.h>


/*
 * Возвращаемое значение:
 * Отрицательное число, если первый аргумент меньше второго.
 * Ноль, если аргументы равны.
 * Положительное число, если первый аргумент больше второго.
 * */
typedef int (*comparator)(const void *, const void *);


int compareId(const void* a, const void* b);


int comparePrice(const void* a, const void* b);


int compareAmount(const void* a, const void* b);


int compareName(const void* a, const void* b);


int compareDescription(const void* a, const void* b);

/*void* base: Указатель на начало массива.

size_t low: Начальный индекс подмассива.

size_t high: Конечный индекс подмассива.

size_t size: Размер одного элемента в байтах.

int (*compar)(const void*, const void*): Указатель на функцию сравнения.
 */
size_t partition(void* base, size_t low, size_t high, size_t size, int (*comparator)(const void*, const void*));


/*void* base: Указатель на начало массива.

size_t nmemb: Количество элементов в массиве.

size_t size: Размер одного элемента в байтах.

int (*compar)(const void*, const void*): Указатель на функцию сравнения.
 */
void quickSort(void* base, size_t low, size_t high, size_t size, int (*comparator)(const void*, const void*));


void myQsort(void* base, size_t nmemb, size_t size, int (*comparator)(const void*, const void*));

#endif //DATABASE_SORTEDBYFIELD_H
