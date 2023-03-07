#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main()
{
    srand(time(NULL)); //난수를 생성하기 위한 초기 시드 값을 설정

    int random[3];
    int i = 0;
    // 중복되지 않는 3자리 수 생성
    while (i < 3)
    {
        //이는 난수를 생성하는 부분
        random[i] = rand() % 10; // 0부터 9까지의 숫자 중에서 랜덤으로 하나를 선택
        for (int j = 0; j < i; j++) //이미 생성된 숫자들과 새로 생성된 숫자를 비교하여 중복 여부를 확인합니다. 
            //j 변수는 이미 생성된 숫자들을 탐색할 때 사용됩니다.
        { 
            if (random[j] == random[i]) //새로 생성된 숫자와 이미 생성된 숫자를 비교하여 중복 여부를 확인합니다.
            {
                i--; // 중복되었다면 i 변수를 1 감소시켜서 다시 동일한 index에서 새로운 숫자를 생성하게 만듭니다.
                break;
            }
        }
        i++;
    }

    int chance = MAX_CHANCE;// 남은 기회
    int try_count = 0;// 시도 횟수
    int game_over = 0;// 게임 종료 여부
    int user[3];// 사용자 입력
    // 게임 진행
    while (!game_over && chance > 0)
    {
        printf("남은 횟수: %d\n\n", chance);
        get_user_input(user);// 사용자 입력 받기
        play_game(random, user, &chance, &try_count, &game_over);
    }

    if (chance == 0)
    {
        printf("\n게임 종료! %d번의 시도 내에 정답을 맞추지 못했습니다. \t정답은 %d%d%d입니다.\n", MAX_CHANCE, random[0], random[1], random[2]);
    }

    return 0;
}