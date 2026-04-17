#include "utils/App.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include "utils/PasswordHasher.h"
int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    return runApp();
}