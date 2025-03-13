//
// Created by mazin on 10.03.2025.
//
#include "sortedByField.h"

int (*comparators[])(const void*, const void*, int) = {
        compareId,       // FIELD_ID
        compareName,     // FIELD_NAME
        compareDescription, // FIELD_DESCRIPTION
        comparePrice,    // FIELD_PRICE
        compareAmount,   // FIELD_AMOUNT
        compareCategoryId // FIELD_CATEGORY_ID
};


int compareWrapper(const void* a, const void* b, void* context) {
    ComparatorWrapper* wrapper = (ComparatorWrapper*) context;
    return wrapper->comparator(a, b, wrapper->order);
}


int compareId(const void* a, const void* b, int order) {
    const Product* objA = (const Product *) a;
    const Product* objB = (const Product *) b;

    if (objA->id < objB->id) return -1 * order;
    if (objA->id > objB->id) return 1 * order;
    return 0;
}


int comparePrice(const void* a, const void* b, int order) {
    const Product * productA = (const Product *) a;
    const Product * productB = (const Product *) b;
    float diff = productA->price - productB->price;

    if (diff < 0) return -1 * order;
    if (diff > 0) return 1 * order;
    return 0;
}


int compareAmount(const void* a, const void* b, int order) {
    const Product * productA = (const Product *) a;
    const Product * productB = (const Product *) b;
    float diff = productA->amount - productB->amount;

    if (diff < 0) return -1 * order;
    if (diff > 0) return 1 * order;
    return 0;
}


int compareName(const void* a, const void* b, int order) {
    const Product * productA = (const Product *) a;
    const Product * productB = (const Product *) b;

    return strcmp(productA->name, productB->name) * order;
}


int compareDescription(const void* a, const void* b, int order) {
    const Product * productA = (const Product *) a;
    const Product * productB = (const Product *) b;

    return (strcmp(productA->description, productB->description)) * order;
}

int compareCategoryId(const void* a, const void* b, int order) {
    const Product* objA = (const Product *) a;
    const Product* objB = (const Product *) b;

    if (objA->id < objB->id) return -1 * order;
    if (objA->id > objB->id) return 1 * order;
    return 0;
}



void swap(void* a, void* b, size_t size) {
    char* p = a;
    char* q = b;
    for (size_t i = 0; i < size; i++) {
        char temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}


size_t partition(void* base, size_t low, size_t high, size_t size,
                 int (*comparator)(const void*, const void*, void*), void* context) {
    char* pivot = (char*)base + high * size;
    size_t i = low;

    for (size_t j = low; j < high; j++) {
        if (comparator((char*)base + j * size, pivot, context) < 0) {
            swap((char*)base + i * size, (char*)base + j * size, size);
            i++;
        }
    }

    swap((char*)base + i * size, pivot, size);
    return i;
}


void quickSort(void* base, size_t low, size_t high, size_t size,
               int (*comparator)(const void*, const void*, void*), void* context) {
    if (low < high) {
        size_t pi = partition(base, low, high, size, comparator, context);

        // Рекурсивная сортировка элементов до и после опорного
        if (pi > 0) quickSort(base, low, pi - 1, size, comparator, context); // Сортировка левой части
        quickSort(base, pi + 1, high, size, comparator, context);            // Сортировка правой части
    }
}


void myQsort(void* base, size_t nmemb, size_t size, int (*comparator)(const void*, const void*, int), int order) {
    ComparatorWrapper wrapper = {comparator, order};
    quickSort(base, 0, nmemb - 1, size, compareWrapper, &wrapper);
}



