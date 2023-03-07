#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main()
{
    srand(time(NULL)); //������ �����ϱ� ���� �ʱ� �õ� ���� ����

    int random[3];
    int i = 0;
    // �ߺ����� �ʴ� 3�ڸ� �� ����
    while (i < 3)
    {
        //�̴� ������ �����ϴ� �κ�
        random[i] = rand() % 10; // 0���� 9������ ���� �߿��� �������� �ϳ��� ����
        for (int j = 0; j < i; j++) //�̹� ������ ���ڵ�� ���� ������ ���ڸ� ���Ͽ� �ߺ� ���θ� Ȯ���մϴ�. 
            //j ������ �̹� ������ ���ڵ��� Ž���� �� ���˴ϴ�.
        { 
            if (random[j] == random[i]) //���� ������ ���ڿ� �̹� ������ ���ڸ� ���Ͽ� �ߺ� ���θ� Ȯ���մϴ�.
            {
                i--; // �ߺ��Ǿ��ٸ� i ������ 1 ���ҽ��Ѽ� �ٽ� ������ index���� ���ο� ���ڸ� �����ϰ� ����ϴ�.
                break;
            }
        }
        i++;
    }

    int chance = MAX_CHANCE;// ���� ��ȸ
    int try_count = 0;// �õ� Ƚ��
    int game_over = 0;// ���� ���� ����
    int user[3];// ����� �Է�
    // ���� ����
    while (!game_over && chance > 0)
    {
        printf("���� Ƚ��: %d\n\n", chance);
        get_user_input(user);// ����� �Է� �ޱ�
        play_game(random, user, &chance, &try_count, &game_over);
    }

    if (chance == 0)
    {
        printf("\n���� ����! %d���� �õ� ���� ������ ������ ���߽��ϴ�. \t������ %d%d%d�Դϴ�.\n", MAX_CHANCE, random[0], random[1], random[2]);
    }

    return 0;
}