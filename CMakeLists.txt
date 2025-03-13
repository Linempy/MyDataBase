cmake_minimum_required(VERSION 3.30)
project(DataBase C)

set(CMAKE_C_STANDARD 11)

add_executable(DataBase main.c
        database/products.h
        database/products.c
        service/getLine.h
        service/getLine.c
        output/outputConsoleDB.c
        output/outputConsoleDB.h
        database/tableColumn.h
        output/formatField.h
        database/productList.c
        database/productList.h
        sorted/sortedByField.c
        sorted/sortedByField.h
        interactionFile/writeFile.c
        interactionFile/writeFile.h
        interactionFile/readFile.c
        interactionFile/readFile.h
        service/splitString.c
        service/splitString.h
        database/tableColumn.c
        interface/cli.c
        interface/cli.h
        lexicon/lexicon.h
        lexicon/lexicon.c
)

include_directories(
        ${CMAKE_SOURCE_DIR}/database
        ${CMAKE_SOURCE_DIR}/service
        ${CMAKE_SOURCE_DIR}/output
        ${CMAKE_SOURCE_DIR}/sorted
        ${CMAKE_SOURCE_DIR}/interactionFile
        ${CMAKE_SOURCE_DIR}/interface
        ${CMAKE_SOURCE_DIR}/lexicon
)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -O2")