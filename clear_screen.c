#include "clear_screen.h"

void clear_screen()
{
    #ifdef __WIN32__
        system("cls");

    #else
        #ifdef __WIN64__
            system("cls");
        #else
        system("clear");
        #endif
    #endif
}