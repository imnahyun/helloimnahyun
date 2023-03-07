#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
/* 사용자 입력을 받는 함수 */
void get_user_input(int user[])
{
    printf("숫자 3개를 입력하세요. (중복 안됨)\n");
    scanf_s("%1d%1d%1d", &user[0], &user[1], &user[2]);
    // 중복된 수를 입력한 경우
   if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
    {
        printf("중복, 다시 입력해주세요.\n");

        
    }
}
/* 게임을 실행하는 함수 */
void play_game(int random[], int user[], int* chance, int* try_count, int* game_over)
{
    int strike = 0;
    int ball = 0;
    // 사용자가 입력한 숫자와 컴퓨터가 생성한 숫자를 비교합니다.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        { // 숫자가 같은 경우
            if (user[i] == random[j])
            {// 자릿수까지 같으면 스트라이크, 자릿수가 다르면 볼로 판단합니다.
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
    // 스트라이크가 3개인 경우 게임종료
    if (strike == 3)
    {
        printf("정답입니다!\n");
        *game_over = 1;// 게임 종료 변수를 1로 설정합니다.
    }// 사용자가 입력한 숫자가 중복되지 않은 경우에만 스트라이크와 볼의 개수를 출력합니다.
    else if (user[0] != user[1] && user[0] != user[2] && user[1] != user[2])
    {
        printf("%d 스트라이크, %d 볼입니다.\t", strike, ball);
        (*chance)--;// 남은 기회를 1 감소시킵니다.
        (*try_count)++;// 시도 횟수를 1 증가시킵니다.
    }
    // 숫자가 중복되거나 사용자가 아웃인 경우 아웃 메시지를 출력하고 남은 기회를 1 감소시킵니다.
    else
    {
        printf("아웃!\t");
        (*chance)--;
    }

    (*try_count)++; // 시도 횟수를 1 증가시켜줍니다.
}