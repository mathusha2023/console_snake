#include "snake.h"
#include "config.h"
#include <stdlib.h>

Snake init_snake(void)
{
    Point centre = {WIDTH / 2, HEIGHT / 2};

    Snake snake;
    snake.length = 1;
    snake.body = malloc(MAX_LENGTH * sizeof(Point));
    *snake.body = centre;
    snake.direction = UP;
    return snake;
}

int grow_snake(Snake *psnake) // 0 - увеличили нормально, 1 - слишком длинная
{
    if (psnake->length == MAX_LENGTH)
        return 1;
    psnake->body[psnake->length++] = (Point){0, 0};
    return 0;
}

void free_snake(Snake *psnake)
{
    free(psnake->body);
}

int move_snake(Snake *psnake) // 0 - игра продолжается, 1 - врезался 
{
    Point movement;
    switch (psnake->direction)
    {
    case UP:
        movement = (Point){0, -1};
        break;
    case DOWN:
        movement = (Point){0, 1};
        break;
    case LEFT:
        movement = (Point){-1, 0};
        break;
    case RIGHT:
        movement = (Point){1, 0};
        break;
    }

    Point *body = psnake->body;
    Point prev = body[0];
    Point prev2 = prev;
    body[0].x += movement.x;
    body[0].y += movement.y;
    int head_x = body[0].x, head_y = body[0].y;

    if (head_x == 0 || head_x == WIDTH - 1 || head_y == 0 || head_y == HEIGHT - 1)
        return 1;
    int i;
    for (i = 1; i < psnake->length; i++)
    {
        if (head_x == body[i].x && head_y == body[i].y)
            return 1;
        prev = body[i];
        body[i] = prev2;
        prev2 = prev;
    }
    return 0;
}