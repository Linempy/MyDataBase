//
// Created by mazin on 09.03.2025.
//

#ifndef DATABASE_TABLECOLUMN_H
#define DATABASE_TABLECOLUMN_H

#include <stddef.h>
#include "formatField.h"

typedef struct {
    const char* header; // Заголовок столбца
    size_t offset;      // Смещение поля в структуре
    FormatField format; // Функция для форматирования значения
    size_t width;          // Ширина столбца
    size_t count;       // кол-во столбцов
} TableColumn;

#endif //DATABASE_TABLECOLUMN_H
