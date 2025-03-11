//
// Created by mazin on 11.03.2025.
//

#ifndef DATABASE_SPLITSTRING_H
#define DATABASE_SPLITSTRING_H

#define MAX_STATIC_SIZE 64

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char** splitString(const char *input, char delimiter, size_t *tokenCount);


#endif //DATABASE_SPLITSTRING_H
