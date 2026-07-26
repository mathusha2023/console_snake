#include "update.h"

int update(Snake *psnake, Fruit *pfruit, clock_t *last_move, const clock_t move_delay,
           int *score) // 0 - игра продолжается, 1 - врезался в стену
{
    clock_t now = clock();
    if (now - *last_move >= move_delay)
    {
        if (move_snake(psnake))
            return 1;
        if ((psnake->body)[0].x == pfruit->x && (psnake->body)[0].y == pfruit->y)
        {
            *score += 10;
            grow_snake(psnake);
            *pfruit = generate_fruit(psnake);
        }
        *last_move = now;
    }

    return 0;
}