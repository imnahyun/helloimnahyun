#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void get_user_input(int user[])
{
    printf("숫자 3개를 입력하세요. (중복 안됨)\n");
    scanf_s("%1d%1d%1d", &user[0], &user[1], &user[2]);
    
   if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
    {
        printf("중복, 다시 입력해주세요.\n");
    }
}

void play_game(int random[], int user[], int* chance, int* try_count, int* game_over)
{
    int strike = 0;
    int ball = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (user[i] == random[j])
            {
                if (i == j)
                {
                    strike++;
                }

                else
                {
                    ball++;
                }
            }
        }
    }

    if (strike == 3)
    {
        printf("정답입니다!\n");
        *game_over = 1;
    }
    else if (user[0] != user[1] && user[0] != user[2] && user[1] != user[2])
    {
        printf("%d 스트라이크, %d 볼입니다.\t", strike, ball);
        (*chance)--;
        (*try_count)++;
    }
    else
    {
        printf("아웃!\t");
        (*chance)--;
    }

    (*try_count)++;
}