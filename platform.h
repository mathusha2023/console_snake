#include "config.h"

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define clear() system("cls")
#define delay() Sleep(SLEEP_TIME)
#define getch() (_kbhit() ? _getch() : '\0')
#define hide_cursor()                                                                                                  \
    {                                                                                                                  \
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);                                                        \
        CONSOLE_CURSOR_INFO info;                                                                                      \
        info.dwSize = 100;                                                                                             \
        info.bVisible = FALSE;                                                                                         \
        SetConsoleCursorInfo(consoleHandle, &info);                                                                    \
    }

#elif __APPLE__
#include <unistd.h>
#include <stdio.h>
#define clear() system("clear")
#define delay() usleep(SLEEP_TIME * 1000)
#define hide_cursor printf("\e[?25l")

#elif __linux__
#include <unistd.h>
#include <stdio.h>
#define clear() system("clear")
#define delay() usleep(SLEEP_TIME * 1000)
#define hide_cursor printf("\e[?25l")

#endif
