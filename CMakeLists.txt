cmake_minimum_required(VERSION 3.7)
project(Projet_connection)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        connection.c
        connection.h
        inscription.c
        inscription.h
        main.c
        structure.h)

add_executable(Projet_connection ${SOURCE_FILES})