#include "draw.h"
#include "input.h"
#include "platform.h"
#include "update.h"

void game()
{
    Snake snake = init_snake();
    Fruit fruit = generate_fruit(&snake);
    int score = 0;

    clock_t last_move = clock();
    const clock_t move_delay = CLOCKS_PER_SEC / 6;

    while (1)
    {
        input(&snake);
        if (update(&snake, &fruit, &last_move, move_delay, &score))
            break;
        draw(&snake, &fruit, score);
        delay();
    }

    free_snake(&snake);
}

int main()
{
    srand(time(NULL));
    hide_cursor();
    clear();
    game();
    return 0;
}
