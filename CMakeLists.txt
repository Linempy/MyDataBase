cmake_minimum_required(VERSION 3.30)
project(DataBase C)

set(CMAKE_C_STANDARD 11)

add_executable(DataBase main.c
        database/products.h
        database/products.c
        service/readLine.h
        service/readLine.c
        output/outputConsoleDB.c
        output/outputConsoleDB.h
        output/tableColumn.h
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
        output/tableColumn.c
)
