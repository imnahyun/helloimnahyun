#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main()
{
    srand(time(NULL));

    int random[3];
    int i = 0;
    while (i < 3)
    {
        random[i] = rand() % 10;
        for (int j = 0; j < i; j++)
        {
            if (random[j] == random[i])
            {
                i--;
                break;
            }
        }
        i++;
    }

    int chance = MAX_CHANCE;
    int try_count = 0;
    int game_over = 0;
    int user[3];

    while (!game_over && chance > 0)
    {
        printf("남은 횟수: %d\n\n", chance);
        get_user_input(user);
        play_game(random, user, &chance, &try_count, &game_over);
    }

    if (chance == 0)
    {
        printf("\n게임 종료! %d번의 시도 내에 정답을 맞추지 못했습니다. \t정답은 %d%d%d입니다.\n", MAX_CHANCE, random[0], random[1], random[2]);
    }

    return 0;
}