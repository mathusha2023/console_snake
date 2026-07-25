#include "fruit.h"
#include "snake.h"
#include <time.h>

int update(Snake *psnake, Fruit *pfruit, clock_t *last_move, const clock_t move_delay, int *score);