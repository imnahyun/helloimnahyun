#define _CRT_SECURE_NO_WARNINGS // scanf �׳� �� �� �ִ� ��, �� ���� ��� ��
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{


	//1. �ҽ��� ���� ������ �� ���ظ� �ϼž� �� + ������ �� �˾ƾ� ��
	//2 draw.io�� ���� �������� �׸���.
	//3. �� 9�� �õ��ϰ� 3��Ʈ����ũ�� �� �ȿ� ������ ������ ���� ����ϰ� ���� ���� ���
	//4. �� ���� 3��Ʈ����ũ�� ������ ���� ��
	//5. �� �� ���� �����ߴ� �� �˷��ֱ�
	//6. �ñ������� ����ó���ؼ� ��ŷ���� ����غ���
	//7. ��ŷ ����� �� ���� �̸� �Է��ؼ� �� �� ����ϰ� �ϱ�



	//srand ���� �Լ�
	//int t = time(NULL); // : �ð� ����
	//srand(t); // rand���ٰ� ���� �ð��� �������� ��Ƽ� ������ ��

		srand(time(NULL));


		int computer[3];
		int i = 0;
		while (i < 3)
		{
			computer[i] = rand() % 10; //0~9 
			for (int j = 0; j < i; j++)
			{
				if (computer[j] == computer[i])
				{
					i--;
					break;
				}
			}
			i++;
		}
		
		printf("���� : ");
		for (int c = 0; c < 3; c++)
		{
			printf("%d\t", computer[c]);
		}
		printf("\n");

		int strike = 0;
		int ball = 0;

		int user[3];
		while (1)
		{
			printf("���� �Է� �ϼ���. 3�� �� ���� �Է��Ͻð� ���� �ߺ��Ǹ� �� �˴ϴ�.\n");
			scanf("%d %d %d", &user[0], &user[1], &user[2]);
			if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2]) //���� �ߺ��� ���
			{
				printf("�ߺ� �߰�\n");
			}
			else
				break;

		}


		//�Է��� �� �ߺ��� ���� �ִ� ���

		for (int i = 0; i < 3; i++)
		{
			if (computer[i] == user[i]) //�ڸ����� ���� �� �Ȱ��� ���
				strike++;
			else
			{
				for (int j = 0; j < 3; j++)
				{
					if (computer[i] == user[j])
						ball++;
				}
			}
		}

		printf("%d ��Ʈ����ũ %d ��\n", strike, ball);



	
	
	return 0;
}