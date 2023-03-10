#include "game.h"

int main()
{
    int random[3]; //3���� ���� ���ڸ� �����ϴ� �迭
    int hint[2]; //��Ʈ�� �����ϴ� �迭
    random_numbers(random, hint);

    int chance = MAX_CHANCE; //���� �õ� Ƚ��
    int try_count = 1; //�õ� Ƚ��
    int game_over = 0; //���� ���� ����
    int user[3]; //������ �Է��� �����ϴ� �迭
    char usernumber[1024]; //������ �Է��� ���ڿ��� �����ϴ� �迭

    while (!game_over && chance > 0)
    {
        printf("���� Ƚ��: %d\n\n", chance); //���� �õ� Ƚ���� ����մϴ�.
        get_user(user, usernumber); //������ �Է��� �޽��ϴ�.
        play_game(random, hint, user, &chance, &try_count, &game_over);       
        // �� �Լ��� ������ �Է��� ���� ������ ���� �񱳸� ���� ��Ʈ�� ����ϰ�, 
        //�õ� Ƚ���� ���� ���� ���θ� �����մϴ�.
    }

    if (chance == 0)
    {
        printf("\n���� ����! %d���� �õ� ���� ������ ������ ���߽��ϴ�. \t������ %d%d%d�Դϴ�.\n", MAX_CHANCE, random[0], random[1], random[2]);
    }

    return 0;
}