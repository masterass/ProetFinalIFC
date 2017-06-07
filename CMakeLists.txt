cmake_minimum_required(VERSION 3.7)
project(Projet_connection)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        connection.c connection.h inscription.c inscription.h verification.c verification.h recherche.c recherche.h main.c
        structure.h clear_screen.h clear_screen.c catalogue.h catalogue.c "tri.c" "tri.h" recherche.c recherche.h conversion.c
        conversion.h espaceperso.c espaceperso.h facture.c facture.h)

add_executable(Projet_connection ${SOURCE_FILES} clear_screen.c catalogue.h catalogue.c "tri.c" "tri.h" recherche.c recherche.h conversion.c conversion.h facture.c facture.h)