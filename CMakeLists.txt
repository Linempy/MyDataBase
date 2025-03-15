cmake_minimum_required(VERSION 3.30)
project(DataBase C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
#set(SDL2_PATH "C:/Users/mazin/Downloads/SDL2-devel-2.32.2-mingw/SDL2-2.32.2/x86_64-w64-mingw32")


#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIR})


add_executable(DataBase main.c
        database/products.c
        service/getLine.c
        output/outputConsoleDB.c
        database/productList.c
        sorted/sortedByField.c
        interactionFile/writeFile.c
        interactionFile/readFile.c
        service/splitString.c
        database/tableColumn.c
        interface/cli.c
        lexicon/lexicon.c
        graphics/sdl.c
        graphics/sdl.h
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

#target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -O2")
