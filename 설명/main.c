#include "game.h"

int main()
{
    int x = 2;
    int y = 3;
    int n = pitagoras(x,y);
    printf("a=%d, b=%d\n", x, y);
    printf("%d %d\n", n, pitagoras(x, y));
    n = pitagorasptr(&x, &y);
    printf("a=%d, b=%d\n", x, y);

    int rr[3]; //3���� ���� ���ڸ� �����ϴ� �迭
    int myhint[2]; //��Ʈ�� �����ϴ� �迭
    random_numbers(rr, myhint);

    int chance = MAX_CHANCE; //���� �õ� Ƚ��. �õ�Ƚ��.
    int try_count = 1; //�õ� Ƚ��
    int game_over = 0; //���� ���� ����
    int user[3]; //������ �Է��� �����ϴ� �迭
    char usernumber[1024]; //������ �Է��� ���ڿ��� �����ϴ� �迭

    while (!game_over && chance > 0)//���ӿ����� 0���� �ƴϰ�, ���� �õ� Ƚ���� 0���̻��̸�
    {
        printf("���� Ƚ��: %d\n\n", chance); //���� �õ� Ƚ���� ����մϴ�.
        get_user(user, usernumber); //������ �Է��� �޽��ϴ�.
        play_game(rr, myhint, user, &chance, &try_count, &game_over);
        // �� �Լ��� ������ �Է��� ���� ������ ���� �񱳸� ���� ��Ʈ�� ����ϰ�, 
        //�õ� Ƚ���� ���� ���� ���θ� �����մϴ�.
    }

    if (chance == 0)
    {
        printf("\n���� ����! %d���� �õ� ���� ������ ������ ���߽��ϴ�. \t������ %d%d%d�Դϴ�.\n", MAX_CHANCE, rr[0], rr[1], rr[2]);
    }

    return 0;
}