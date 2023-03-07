#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
/* ����� �Է��� �޴� �Լ� */
void get_user_input(int user[])
{
    printf("���� 3���� �Է��ϼ���. (�ߺ� �ȵ�)\n");
    scanf_s("%1d%1d%1d", &user[0], &user[1], &user[2]);
    // �ߺ��� ���� �Է��� ���
   if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2])
    {
        printf("�ߺ�, �ٽ� �Է����ּ���.\n");

        
    }
}
/* ������ �����ϴ� �Լ� */
void play_game(int random[], int user[], int* chance, int* try_count, int* game_over)
{
    int strike = 0;
    int ball = 0;
    // ����ڰ� �Է��� ���ڿ� ��ǻ�Ͱ� ������ ���ڸ� ���մϴ�.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        { // ���ڰ� ���� ���
            if (user[i] == random[j])
            {// �ڸ������� ������ ��Ʈ����ũ, �ڸ����� �ٸ��� ���� �Ǵ��մϴ�.
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
    // ��Ʈ����ũ�� 3���� ��� ��������
    if (strike == 3)
    {
        printf("�����Դϴ�!\n");
        *game_over = 1;// ���� ���� ������ 1�� �����մϴ�.
    }// ����ڰ� �Է��� ���ڰ� �ߺ����� ���� ��쿡�� ��Ʈ����ũ�� ���� ������ ����մϴ�.
    else if (user[0] != user[1] && user[0] != user[2] && user[1] != user[2])
    {
        printf("%d ��Ʈ����ũ, %d ���Դϴ�.\t", strike, ball);
        (*chance)--;// ���� ��ȸ�� 1 ���ҽ�ŵ�ϴ�.
        (*try_count)++;// �õ� Ƚ���� 1 ������ŵ�ϴ�.
    }
    // ���ڰ� �ߺ��ǰų� ����ڰ� �ƿ��� ��� �ƿ� �޽����� ����ϰ� ���� ��ȸ�� 1 ���ҽ�ŵ�ϴ�.
    else
    {
        printf("�ƿ�!\t");
        (*chance)--;
    }

    (*try_count)++; // �õ� Ƚ���� 1 ���������ݴϴ�.
}