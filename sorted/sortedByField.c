//
// Created by mazin on 10.03.2025.
//
#include "sortedByField.h"

int compareId(const void* a, const void* b) {
    const Product* objA = (const Product *) a;
    const Product* objB = (const Product *) b;

    if (objA->id < objB->id) return -1;
    if (objA->id > objB->id) return 1;
    return 0;
}


int comparePrice(const void* a, const void* b) {
    const Product * productA = (const Product *) a;
    const Product * productB = (const Product *) b;
    float diff = productA->price - productB->price;

    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}


int compareAmount(const void* a, const void* b) {
    const Product * productA = (const Product *) a;
    const Product * productB = (const Product *) b;
    float diff = productA->amount - productB->amount;

    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}


int compareName(const void* a, const void* b) {
    const Product * productA = (const Product *) a;
    const Product * productB = (const Product *) b;

    return strcmp(productA->name, productB->name);
}


int compareDescription(const void* a, const void* b) {
    const Product * productA = (const Product *) a;
    const Product * productB = (const Product *) b;

    return strcmp(productA->description, productB->description);
}


// Функция для обмена двух элементов
void swap(void* a, void* b, size_t size) {
    char* p = a;
    char* q = b;
    for (size_t i = 0; i < size; i++) {
        char temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}


// Функция разделения (partition)
size_t partition(void* base, size_t low, size_t high, size_t size, int (*comparator)(const void*, const void*)) {
    char* pivot = (char*)base + high * size; // Опорный элемент (последний)
    size_t i = low; // Индекс меньшего элемента

    for (size_t j = low; j < high; j++) {
        if (comparator((char*)base + j * size, pivot) < 0) {
            swap((char*)base + i * size, (char*)base + j * size, size);
            i++;
        }
    }

    // Помещаем опорный элемент на правильное место
    swap((char*)base + i * size, pivot, size);
    return i;
}


// Основная функция QuickSort
void quickSort(void* base, size_t low, size_t high, size_t size, int (*comparator)(const void*, const void*)) {
    if (low < high) {
        // Индекс опорного элемента
        size_t pi = partition(base, low, high, size, comparator);

        // Рекурсивно сортируем элементы до и после опорного
        if (pi > 0) quickSort(base, low, pi - 1, size, comparator); // Сортировка левой части
        quickSort(base, pi + 1, high, size, comparator);            // Сортировка правой части
    }
}


// Обёртка для удобства (аналог qsort)
void myQsort(void* base, size_t nmemb, size_t size, int (*comparator)(const void*, const void*)) {
    quickSort(base, 0, nmemb - 1, size, comparator);
}
