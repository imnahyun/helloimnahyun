#include "game.h" // game.h 파일을 불러옴


void random_numbers(int random[], int hint[]) // 랜덤 숫자와 힌트를 생성하는 함수
{
    srand(time(NULL)); // seed 값을 현재 시간으로 설정

    int i = 0; // 인덱스 변수 i를 0으로 초기화
    while (i < 3) // 3개의 랜덤 숫자를 생성하기 위한 while 루프
    {
        random[i] = rand() % 10; // 0~9 사이의 랜덤 숫자 생성
        for (int j = 0; j < i; j++) // 중복되지 않도록 검사하기 위한 for 루프
        {
            if (random[j] == random[i]) // 이미 생성된 숫자와 같은 숫자가 있을 경우
            {
                i--; // 현재 인덱스에서 다시 검사하기 위해 i 값을 감소시킴
                break; // for 루프를 종료하고 while 루프에서 다시 랜덤 숫자 생성
            }
        }
        i++; // 중복되지 않는 랜덤 숫자가 생성되면 인덱스 값을 증가시킴
    }

    for (int index = 0; index < 2; index++) // 힌트를 생성하기 위한 for 루프
    {
        hint[index] = rand()%10;
        if (hint[index] == random[0] || hint[index] == random[1] || hint[index] == random[2]) 
            // 생성된 힌트 숫자가 랜덤 숫자와 같은 경우
        {
            index--; // 다시 생성하기 위해 인덱스 값을 감소시킴
        }
        if (index == 1 && hint[0] == hint[1])
           
            index--;
   
    }
}
int get_user(int user[], char usernumber[]) // 유저로부터 입력받는 함수
{
    while (1) // 유저가 제대로 입력할 때까지 무한 루프를 돌림
    {
        printf("숫자 3개를 입력하세요. (중복 안됨)\n");
        gets(usernumber); // 유저가 입력한 값을 문자열로 읽어옴
        int digitCount = 0;  // 자리수를 저장하기 위한 변수 digitCount를 0으로 초기화
        for (; digitCount < 4; digitCount++) // 3자리 입력받기 위한 for 루프
        {
            if (usernumber[digitCount] == NULL)  // 입력받은 값이 NULL인 경우 (문자열 끝까지 입력받은 경우)
            {
                break;
            }
        }
        if (digitCount != 3)
        {//digitCount가 3이 아니면, "3자리 입력"이라는 메시지를 출력하고 
            //다시 입력을 받도록 continue를 사용하여 반복문의 다음 순회를 진행합니다.
            printf("3자리 입력\n");
            continue;
        }
        //숫자가 아니면 "잘못된 값"이라는 메시지를 출력하고 다시 입력
        if (usernumber[0] < '0' || usernumber[0] >'9' || usernumber[1] < '0' || usernumber[1] >'9' || usernumber[2] < '0' || usernumber[2] >'9')
        {
            printf("잘못된 값.\n");
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
     //문자열을 숫자로 변환하여 user 배열에 저장합니다.
     //'0'을 뺀 값이 실제 숫자 값입니다.
            user[i] = usernumber[i] - '0';
        }
        // 사용자가 입력한 숫자에 중복된 값이 있으면 
        //다시 입력을 받기 위해 반복문의 처음으로 돌아갑니다.
        if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
        {
            printf("중복, 다시 입력해주세요.\n");
            continue;

        }
        break;
    }
}
void play_game(int random[], int hint[], int user[], int* chance, int* try_count, int* game_over)
{
    int strike = 0;
    int ball = 0;
    // 사용자가 입력한 숫자와 랜덤한 숫자를 비교하여 strike와 ball의 개수를 계산합니다.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (user[i] == random[j])
            {// 숫자가 같은 자리에 있으면 strike를 1 증가시킵니다
                if (i == j)
                {
                    strike++;
                }
                // 숫자가 다른 자리에 있으면 ball을 1 증가시킵니다.
                else
                {
                    ball++;
                }
            }

        }
    }
    //스트라이크인 경우 성공 메시지를 출력하고 game_over를 1로 설정합니다.
    if (strike == 3)
    {
        printf("%d번째 시도에 성공했습니다.\n", *try_count);
        *game_over = 1;
        return;
    }
    // 시도 횟수가 2번인 경우 힌트를 제공합니다.
    if (*try_count == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (user[i] == hint[0])
            {
                printf("[ %d ]는 확실히 없어요\n", user[i]);
                return;
            }
        }
    }
    // 시도 횟수가 4번인 경우 두번 째 힌트를 제공합니다.
    if (*try_count == 4)
    {
        for (int i = 0; i < 3; i++)
        {
            if (user[i] == hint[0] || user[i] == hint[1])
            {
                printf("[ %d ]는 확실히 없어요\n", user[i]);
                return;
            }
        }
    }
    // strike와 ball이 모두 0인 경우 아웃 메시지를 출력합니다.
    if (strike == 0 && ball == 0)
    {
        printf("아웃!\t");
    }
    // strike나 ball이 있는 경우 해당 개수를 출력합니다.
    else 
    {
        printf("%d 스트라이크, %d 볼입니다.\t", strike, ball);
    }
    // 남은 기회를 1 감소시키고 시도 횟수를 1 증가시킵니다.
    (*chance)--;
    (*try_count)++;
}


