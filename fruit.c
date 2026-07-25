#include "fruit.h"
#include "config.h"
#include <stdlib.h>

static int is_into(int x, int y, Snake *psnake)
{
    for (int i = 0; i < psnake->length; i++)
    {
        if (x == psnake->body[i].x && y == psnake->body[i].y)
            return 1;
    }
    return 0;
}

Fruit generate_fruit(Snake *psnake)
{
    int x = rand() % (WIDTH - 2) + 1;
    int y = rand() % (HEIGHT - 2) + 1;

    while (is_into(x, y, psnake))
    {
        x = rand() % (WIDTH - 2) + 1;
        y = rand() % (HEIGHT - 2) + 1;
    }

    return (Fruit){x, y};
};
