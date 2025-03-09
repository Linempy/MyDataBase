//
// Created by mazin on 09.03.2025.
//
#include "visualWidth.h"

size_t visualWidth(const char *str) {
    size_t width = 0;
    while (*str) {
        if ((*str & 0xC0) != 0x80) { // Начало нового символа UTF-8
            if ((unsigned char)*str >= 0xC0) { // Кириллица или другие многобайтовые символы
                width += 2;
            } else {
                width += 1; // ASCII символы
            }
        }
        str++;
    }
    return width;
}