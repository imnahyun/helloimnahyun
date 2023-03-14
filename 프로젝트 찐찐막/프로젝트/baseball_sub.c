#include "baseball.h"
#include "menu.h"
#include "Dino_head.h"

void count1(int* start_time)
{
    *start_time = time(NULL); // ���� ����
    getchar(); //���� �Դ� ����
}


void random_numbers(int random[], int hint[]) // �������� ����
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
        hint[index] = rand() % 10;
        if (hint[index] == random[0] || hint[index] == random[1] || hint[index] == random[2])
        {
            index--;
        }
        if (index == 1 && hint[0] == hint[1])

            index--;

    }
}
void get_user(int user[], char usernumber[]) // �����Է¹���
{
    printf("���� 3���� �Է��ϼ���. (�ߺ� �ȵ�)\n");

    while (1)
    {
        gets(usernumber);
        int digitCount = 0;
        for (; digitCount < 4; digitCount++)
        {
            if (usernumber[digitCount] == NULL)
            {
                break;
            }
        }
        if (digitCount != 3)
        {
            printf("3�ڸ� �Է�\n");
            continue;
        }
        if (usernumber[0] < '0' || usernumber[0] >'9' || usernumber[1] < '0' || usernumber[1] >'9' || usernumber[2] < '0' || usernumber[2] >'9')
        {
            printf("�߸��� ��.\n");
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
            user[i] = usernumber[i] - '0';
        }
        if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
        {
            printf("�ߺ�, �ٽ� �Է����ּ���.\n");
            continue;

        }

        break;
    }
}
void start_game(int random[], int hint[], int user[], int* chance, int* try_count, int* game_over, int start_time)
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
        int end_time = time(NULL);
        int elapsed_time = end_time - start_time;
        system("mode con cols=110 lines=50");
        system("cls");
        printTxtFile("win.txt");
        printf("%d��° �õ��� �����߽��ϴ�.\n", *try_count);
        printf("�ҿ�� �ð��� %d�� �Դϴ�.\n", elapsed_time);
        //count2();

        printf("�÷��̾� �̸��� �Է����ּ���(�ѱ�����) : ");

        char name[50];
        scanf_s("%s", name, (unsigned)_countof(name));



        FILE* file = NULL;
        errno_t err = fopen_s(&file, "baseball.txt", "a");
        if (err != 0)
        {
            printf("���� ���⿡ �����߽��ϴ�.");
            exit(1);
        }

        fprintf(file, "%s %d\n", name, elapsed_time);
        fclose(file);

        printf("\n\n\n\n\n\n\n");
        printf("���ϴ� �޴��� �Է����ּ��� (r = �����, e = �޴�, w = ����) : ");

        char input;
        do
        {
            input = getchar();
        } while (input != 'r' && input != 'e' && input != 'w');

        if (input == 'r')
        {
            play_baseball();
        }
        else if (input == 'e')
        {
            system("cls");
            system("mode con cols=100 lines=40"); // �ܼ�â ũ�� ����
            playMusic("C:\\Users\\KB\\Desktop\\music.wav");
            printTxtFile("text.txt");
            menu();
        }

        else if (input == 'w')
        {
            system("mode con cols=100 lines=40"); // �ܼ�â ũ�� ����
            printTxtFile("text.txt");
            printf("\n                                         ������ ����Ǿ����ϴ�.\n");
            exit(0);
        }
        *game_over = 1;
        return ;
    }
    if (*try_count == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (user[i] == hint[0])
            {
                printf("[ %d ]�� �����\n", user[i]);
                return;
            }
        }
    }
    if (*try_count == 4)
    {
        for (int i = 0; i < 3; i++)
        {
            if (user[i] == hint[0] || user[i] == hint[1])
            {
                printf("[ %d ]�� �����\n", user[i]);
                return;
            }
        }
    }
    if (strike == 0 && ball == 0)
    {
        printf("0��Ʈ����ũ 0���Դϴ�.\n");
    }
    else
    {
        printf("%d ��Ʈ����ũ, %d ���Դϴ�.\n\n", strike, ball);
    }
    (*chance)--;
    (*try_count)++;
}
void gameover(int* random, int *hint, const int sec, int start_time)
{

    int chance = MAX_CHANCE;
    int try_count = 1;
    int game_over = 0;
    int user[3];
    char usernumber[1024];
    int end_time = time(NULL);
    int elapsed_time = end_time - start_time;
    while (!game_over && chance > 0)
    {
        printf("���� Ƚ��: %d\n\n", chance);
        get_user(user, usernumber);
        start_game(random, hint, user, &chance, &try_count, &game_over, start_time);

    }


    if (chance == 0)
    {
        system("mode con cols=110 lines=50");
        system("cls");
        printTxtFile("lose.txt");
        printf("\n���� ����! %d���� �õ� ���� ������ ������ ���߽��ϴ�. \t������ %d%d%d�Դϴ�.\n", MAX_CHANCE, random[0], random[1], random[2]);


        printf("\n\n\n\n\n\n\n");
        printf("���ϴ� �޴��� �Է����ּ��� (r = �����, e = �޴�, w = ����) : ");

        char input;
        do
        {
            input = getchar();
        } while (input != 'r' && input != 'e' && input != 'w');

        if (input == 'r')
        {
            play_baseball();
        }
        else if (input == 'e')
        {
            system("cls");
            system("mode con cols=100 lines=40"); // �ܼ�â ũ�� ����
            playMusic("C:\\Users\\KB\\Desktop\\music.wav");
            printTxtFile("text.txt");
            menu();
        }

        else if (input == 'w')
        {
            system("mode con cols=100 lines=40"); // �ܼ�â ũ�� ����
            printTxtFile("text.txt");
            printf("\n                                         ������ ����Ǿ����ϴ�.\n");
            exit(0);
        }
    }


}



void play_baseball()
{
    
    CursorView(0);
    start();
    int start_time;
    count1(&start_time);
    system("cls");
    playMusic("C:\\Users\\KB\\Desktop\\music3.wav");
    int random[3];
    int hint[2];

    //char c = getchar();
    random_numbers(random, hint);
    int sec = 0;
    gameover(random, hint,sec,start_time);

}
