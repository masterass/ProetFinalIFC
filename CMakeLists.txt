cmake_minimum_required(VERSION 3.7)
project(Projet_connection)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        connection.c
        connection.h
        inscription.c
        inscription.h
        verification.c
        verification.h
        main.c
        structure.h Utilisateurs/clear_screen.h Utilisateurs/clear_sceen.c)

add_executable(Projet_connection ${SOURCE_FILES} Utilisateurs/clear_screen.h Utilisateurs/clear_sceen.c)