#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void get_user_input(int user[])
{
    printf("���� 3���� �Է��ϼ���. (�ߺ� �ȵ�)\n");
    scanf_s("%1d%1d%1d", &user[0], &user[1], &user[2]);
    
   if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
    {
        printf("�ߺ�, �ٽ� �Է����ּ���.\n");
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
        printf("�����Դϴ�!\n");
        *game_over = 1;
    }
    else if (user[0] != user[1] && user[0] != user[2] && user[1] != user[2])
    {
        printf("%d ��Ʈ����ũ, %d ���Դϴ�.\t", strike, ball);
        (*chance)--;
        (*try_count)++;
    }
    else
    {
        printf("�ƿ�!\t");
        (*chance)--;
    }

    (*try_count)++;
}