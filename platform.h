#include "config.h"

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define clear() system("cls")
#define delay() Sleep(1)
#define getch() (_kbhit() ? _getch() : '\0')
#define hide_cursor()                                           \
    {                                                           \
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); \
        CONSOLE_CURSOR_INFO info;                               \
        info.dwSize = 100;                                      \
        info.bVisible = FALSE;                                  \
        SetConsoleCursorInfo(consoleHandle, &info);             \
    }

#elif defined(__APPLE__) || defined(__linux__)
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/select.h>

static struct termios orig_termios;
static int termios_saved = 0;

static void restore_terminal(void)
{
    if (termios_saved)
    {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
        termios_saved = 0;
    }
}

static void set_noncanon_mode(void)
{
    if (!termios_saved)
    {
        tcgetattr(STDIN_FILENO, &orig_termios);
        atexit(restore_terminal); // автоматическое восстановление при выходе
        termios_saved = 1;
    }
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO); // убрать канонический режим и эхо
    raw.c_cc[VMIN] = 0;              // минимальное число символов для read(): 0 (неблокирующий)
    raw.c_cc[VTIME] = 0;             // таймаут 0
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

static int unix_kbhit(void)
{
    set_noncanon_mode(); // однократно настраиваем терминал
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);
    struct timeval tv = {0, 0}; // немедленный возврат
    return select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv) == 1;
}

static int unix_getch(void)
{
    unsigned char c;
    if (read(STDIN_FILENO, &c, 1) == 1)
        return c;
    return EOF;
}

#define clear() system("clear")
#define delay() usleep(1000)
#define getch() (unix_kbhit() ? unix_getch() : '\0')
#define hide_cursor() printf("\e[?25l")

#endif
