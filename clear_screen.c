#include "clear_screen.h"

void clear_screen()
{
#if defined (OS_WINDOWS)
    system ("cls");
#else
#if defined (OS_LINUX)
    system ("clear");
#endif
#endif
}

/**void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}**/