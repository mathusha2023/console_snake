#include "platform.h"
#include "input.h"
#include <ctype.h>

void input(Snake *psnake)
{
    switch (tolower(getch()))
    {
    case 'w':
        if (psnake->direction != DOWN)
            psnake->direction = UP;
        break;
    case 's':
        if (psnake->direction != UP)
            psnake->direction = DOWN;
        break;
    case 'a':
        if (psnake->direction != RIGHT)
            psnake->direction = LEFT;
        break;
    case 'd':
        if (psnake->direction != LEFT)
            psnake->direction = RIGHT;
        break;
    }
}
