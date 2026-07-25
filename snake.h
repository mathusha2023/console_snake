#ifndef SNAKE_H
#define SNAKE_H

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    Point *body;
    int length;
    enum Direction direction;
} Snake;

Snake init_snake(void);
int grow_snake(Snake *snake);
void free_snake(Snake *psnake);
int move_snake(Snake *psnake);

#endif