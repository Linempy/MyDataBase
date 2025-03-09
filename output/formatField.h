//
// Created by mazin on 09.03.2025.
//

#ifndef DATABASE_FORMATFIELD_H
#define DATABASE_FORMATFIELD_H

#include <stddef.h>

typedef void (*FormatField)(char* dest, size_t destSize, const void* field);


#endif //DATABASE_FORMATFIELD_H
