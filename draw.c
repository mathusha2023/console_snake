#include "config.h"
#include "platform.h"
#include "draw.h"
#include <stdio.h>

void draw(Snake *psnake, Fruit *pfruit, int score)
{
    clear();
    char field[HEIGHT][WIDTH];

    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (i == 0 || i == HEIGHT - 1)
                field[i][j] = '-';
            else if (j == 0 || j == WIDTH - 1)
                field[i][j] = '|';
            else
                field[i][j] = '.';
        }
    }

    Point *body = psnake->body;
    for (i = 0; i < psnake->length; i++)
    {
        int x = body[i].x;
        int y = body[i].y;
        field[y][x] = !i ? '@' : '*';
    }

    field[pfruit->y][pfruit->x] = '#';

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%c", field[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    printf("Score: %d\n", score);
    printf("Total length: %d\n", psnake->length);
    printf("\n\n\n");
}
