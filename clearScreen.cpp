// ClearScreen function will clear the screen both in a Windows environment as well as in a Linux environment.
//
#include <iostream>
#include <stdlib.h>                     /*for system()*/
using namespace std;

#ifdef __unix__                         /* __unix__ is usually defined by compilers targeting Unix systems */
#define OS_Windows 0
#elif defined(_WIN32) || defined(WIN32) /* _Win32 is usually defined by compilers targeting 32 or 64 bit Windows systems */
#define OS_Windows 1
#include <windows.h>
#endif

int clearScreen() {

    if (OS_Windows) {
        system("CLS");
    }
    else {
        system("clear");
    }
    return 0;
}