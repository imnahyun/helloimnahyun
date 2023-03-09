#include "game.h"


void random_numbers(int random[], int not_random[])
{
    srand(time(NULL));

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

    for (int index = 0; index < 2; index++)
    {
        not_random[index] = rand()%10;
        if (not_random[index] == random[0] || not_random[index] == random[1] || not_random[index] == random[2])
        {
            index--;
        }
        if (index == 1 && not_random[0] == not_random[1])
           
            index--;
   
    }

}
int get_user(int user[], char usernumber[])
{

    while (1)
    {
        printf("숫자 3개를 입력하세요. (중복 안됨)\n");
        gets(usernumber);
        //0자리, 1자리, 2자리,4자리 이상이면 오류
        int digitCount = 0; //자릿수, 무조건 3이 나와야함
        for (; digitCount < 4; digitCount++)
        {
            if (usernumber[digitCount] == NULL)
            {
                break;
            }
        }
        if (digitCount != 3)
        {
            printf("3자리 입력\n");
            continue;
        }
        //ABC 이런거
        //아니면 9A0 이런 거 하면 한 자리라도 숫자가 아닌 게 들어가면 다시 시도해야 함
        if (usernumber[0] < '0' || usernumber[0] >'9' || usernumber[1] < '0' || usernumber[1] >'9' || usernumber[2] < '0' || usernumber[2] >'9')
        {
            printf("잘못된 값.\n");
            continue;
        }


        //세자리가 정상적으로 들어갔다면 바꾸기
        for (int i = 0; i < 3; i++)
        {
            user[i] = usernumber[i] - '0';
        }

        if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
        {
            printf("중복, 다시 입력해주세요.\n");
            continue;

        }
        break;
    }
}

void play_game(int random[], int not_random[], int user[], int* chance, int* try_count, int* game_over)
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
        return;
    }
   
    if (*try_count == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (user[i] == not_random[0])
            {
                printf("%d는 확실히 없어요\n", user[i]);
                return;
            }
        }
    }

    if (*try_count == 4)
    {
        for (int i = 0; i < 3; i++)
        {
            if (user[i] == not_random[0] || user[i] == not_random[1])
            {
                printf("%d는 확실히 없어요\n", user[i]);
                return;
            }
        }
    }

    if (strike == 0 && ball == 0)
    {
        printf("아웃!\t");



    }

    else 
    {
        printf("%d 스트라이크, %d 볼입니다.\t", strike, ball);
    }


    (*chance)--;
    (*try_count)++;
}


