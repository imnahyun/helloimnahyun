#include "game.h"

int main()
{
    int random[3]; //3개의 랜덤 숫자를 저장하는 배열
    int hint[2]; //힌트를 저장하는 배열
    random_numbers(random, hint);

    int chance = MAX_CHANCE; //남은 시도 횟수
    int try_count = 1; //시도 횟수
    int game_over = 0; //게임 종료 여부
    int user[3]; //유저의 입력을 저장하는 배열
    char usernumber[1024]; //유저의 입력을 문자열로 저장하는 배열

    while (!game_over && chance > 0)
    {
        printf("남은 횟수: %d\n\n", chance); //남은 시도 횟수를 출력합니다.
        get_user(user, usernumber); //유저의 입력을 받습니다.
        play_game(random, hint, user, &chance, &try_count, &game_over);       
        // 이 함수는 유저가 입력한 값과 랜덤한 값의 비교를 통해 힌트를 출력하고, 
        //시도 횟수와 게임 종료 여부를 결정합니다.
    }

    if (chance == 0)
    {
        printf("\n게임 종료! %d번의 시도 내에 정답을 맞추지 못했습니다. \t정답은 %d%d%d입니다.\n", MAX_CHANCE, random[0], random[1], random[2]);
    }

    return 0;
}