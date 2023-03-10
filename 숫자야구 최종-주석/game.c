#include "game.h" // game.h ������ �ҷ���


void random_numbers(int random[], int hint[]) // ���� ���ڿ� ��Ʈ�� �����ϴ� �Լ�
{
    srand(time(NULL)); // seed ���� ���� �ð����� ����

    int i = 0; // �ε��� ���� i�� 0���� �ʱ�ȭ
    while (i < 3) // 3���� ���� ���ڸ� �����ϱ� ���� while ����
    {
        random[i] = rand() % 10; // 0~9 ������ ���� ���� ����
        for (int j = 0; j < i; j++) // �ߺ����� �ʵ��� �˻��ϱ� ���� for ����
        {
            if (random[j] == random[i]) // �̹� ������ ���ڿ� ���� ���ڰ� ���� ���
            {
                i--; // ���� �ε������� �ٽ� �˻��ϱ� ���� i ���� ���ҽ�Ŵ
                break; // for ������ �����ϰ� while �������� �ٽ� ���� ���� ����
            }
        }
        i++; // �ߺ����� �ʴ� ���� ���ڰ� �����Ǹ� �ε��� ���� ������Ŵ
    }

    for (int index = 0; index < 2; index++) // ��Ʈ�� �����ϱ� ���� for ����
    {
        hint[index] = rand()%10;
        if (hint[index] == random[0] || hint[index] == random[1] || hint[index] == random[2]) 
            // ������ ��Ʈ ���ڰ� ���� ���ڿ� ���� ���
        {
            index--; // �ٽ� �����ϱ� ���� �ε��� ���� ���ҽ�Ŵ
        }
        if (index == 1 && hint[0] == hint[1])
           
            index--;
   
    }
}
int get_user(int user[], char usernumber[]) // �����κ��� �Է¹޴� �Լ�
{
    while (1) // ������ ����� �Է��� ������ ���� ������ ����
    {
        printf("���� 3���� �Է��ϼ���. (�ߺ� �ȵ�)\n");
        gets(usernumber); // ������ �Է��� ���� ���ڿ��� �о��
        int digitCount = 0;  // �ڸ����� �����ϱ� ���� ���� digitCount�� 0���� �ʱ�ȭ
        for (; digitCount < 4; digitCount++) // 3�ڸ� �Է¹ޱ� ���� for ����
        {
            if (usernumber[digitCount] == NULL)  // �Է¹��� ���� NULL�� ��� (���ڿ� ������ �Է¹��� ���)
            {
                break;
            }
        }
        if (digitCount != 3)
        {//digitCount�� 3�� �ƴϸ�, "3�ڸ� �Է�"�̶�� �޽����� ����ϰ� 
            //�ٽ� �Է��� �޵��� continue�� ����Ͽ� �ݺ����� ���� ��ȸ�� �����մϴ�.
            printf("3�ڸ� �Է�\n");
            continue;
        }
        //���ڰ� �ƴϸ� "�߸��� ��"�̶�� �޽����� ����ϰ� �ٽ� �Է�
        if (usernumber[0] < '0' || usernumber[0] >'9' || usernumber[1] < '0' || usernumber[1] >'9' || usernumber[2] < '0' || usernumber[2] >'9')
        {
            printf("�߸��� ��.\n");
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
     //���ڿ��� ���ڷ� ��ȯ�Ͽ� user �迭�� �����մϴ�.
     //'0'�� �� ���� ���� ���� ���Դϴ�.
            user[i] = usernumber[i] - '0';
        }
        // ����ڰ� �Է��� ���ڿ� �ߺ��� ���� ������ 
        //�ٽ� �Է��� �ޱ� ���� �ݺ����� ó������ ���ư��ϴ�.
        if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
        {
            printf("�ߺ�, �ٽ� �Է����ּ���.\n");
            continue;

        }
        break;
    }
}
void play_game(int random[], int hint[], int user[], int* chance, int* try_count, int* game_over)
{
    int strike = 0;
    int ball = 0;
    // ����ڰ� �Է��� ���ڿ� ������ ���ڸ� ���Ͽ� strike�� ball�� ������ ����մϴ�.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (user[i] == random[j])
            {// ���ڰ� ���� �ڸ��� ������ strike�� 1 ������ŵ�ϴ�
                if (i == j)
                {
                    strike++;
                }
                // ���ڰ� �ٸ� �ڸ��� ������ ball�� 1 ������ŵ�ϴ�.
                else
                {
                    ball++;
                }
            }

        }
    }
    //��Ʈ����ũ�� ��� ���� �޽����� ����ϰ� game_over�� 1�� �����մϴ�.
    if (strike == 3)
    {
        printf("%d��° �õ��� �����߽��ϴ�.\n", *try_count);
        *game_over = 1;
        return;
    }
    // �õ� Ƚ���� 2���� ��� ��Ʈ�� �����մϴ�.
    if (*try_count == 2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (user[i] == hint[0])
            {
                printf("[ %d ]�� Ȯ���� �����\n", user[i]);
                return;
            }
        }
    }
    // �õ� Ƚ���� 4���� ��� �ι� ° ��Ʈ�� �����մϴ�.
    if (*try_count == 4)
    {
        for (int i = 0; i < 3; i++)
        {
            if (user[i] == hint[0] || user[i] == hint[1])
            {
                printf("[ %d ]�� Ȯ���� �����\n", user[i]);
                return;
            }
        }
    }
    // strike�� ball�� ��� 0�� ��� �ƿ� �޽����� ����մϴ�.
    if (strike == 0 && ball == 0)
    {
        printf("�ƿ�!\t");
    }
    // strike�� ball�� �ִ� ��� �ش� ������ ����մϴ�.
    else 
    {
        printf("%d ��Ʈ����ũ, %d ���Դϴ�.\t", strike, ball);
    }
    // ���� ��ȸ�� 1 ���ҽ�Ű�� �õ� Ƚ���� 1 ������ŵ�ϴ�.
    (*chance)--;
    (*try_count)++;
}


