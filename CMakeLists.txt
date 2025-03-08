cmake_minimum_required(VERSION 3.30)
project(DataBase C)

set(CMAKE_C_STANDARD 11)

add_executable(DataBase main.c
        products.h
        products.c
        readLine.h
        readLine.c
)
