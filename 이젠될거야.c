#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGIT 3 //�� �ڸ���
#define LENGTH 4  //�迭�� ũ��(3�ڸ� ���ڿ� �Է��ؾ� ��
#define TRYCOUNT 9

int main() {


	int computer[DIGIT];
	int user[DIGIT];
	char usernumber[LENGTH];
	int i, j;
	int num;
	int count=1;
	int hint[2];

	srand(time(NULL));


	for (i = 0; i < DIGIT; i++) {
		num = rand() % 10;
		computer[i] = num;
		for (j = 0; j < i; j++) {
			if (computer[j] == computer[i]) {
				i--;
				break;

			}

		}

	}
	for (int index = 0; index < 2; index++)
	{
		hint[index] = rand() % 10;
		if (hint[index] == computer[0] || hint[index] == computer[1] || hint[index] == computer[2])
		{
			index--;
		}
		if (index == 1 && hint[0] == hint[1]) {
			index--;
		}
	}
	printf("���� %d���� �Է��Ͽ� ���ھ߱������� �غ��ÿ�!\n", DIGIT);
	
	
	
	while (1) {
		

		printf("%d �ڸ� ���� �Է��ϼ���.\n", DIGIT);
		gets(usernumber);
		//0�ڸ�, 1�ڸ�, 2�ڸ�, 4�ڸ� �̻��̸� ����
		int digitCount = 0; //�ڸ���, ������ 3�� ���;� ��

		for (; digitCount < LENGTH; digitCount++)
		{
			if (usernumber[digitCount] == NULL)
			{
				break;
			}
		}
		if (digitCount != DIGIT)
		{
			printf("%d�ڸ��� �Է��ؾ� �մϴ�.\n", DIGIT);
			continue;
		}
		
		//�� �ڸ��� ���������� ���Դٸ� �ٲٱ�
		for (int i = 0; i < DIGIT; i++)
		{
			user[i] = usernumber[i] - '0'; //�� ���ڵ��� �ƽ�Ű���� 10�� �Ѵ� ���̹Ƿ�
			//'0'��ŭ ���� �� ���ڵ��� ���� 0~9���� �ǵ��� �ϱ�
		}
	

		if (user[0] < 0 || user[0] > 9 || user[1] < 0 || user[1] > 9 || user[2] < 0 || user[2] > 9) {
			printf("0~9������ ���ڸ� �ϳ��� �Է��ؾ��մϴ�.\n");
			continue;
		}
		if (user[0] == user[1] || user[1] == user[2] || user[2] == user[0]) {
			printf("�ߺ��� �����Դϴ�\n");
			continue;
		}


		int strike = 0, ball = 0;
		for (i = 0; i < DIGIT; i++)
		{
			for (j = 0; j < DIGIT; j++)
			{

				if (computer[i] == user[j]) {
					if (i == j) {
						strike++;
					}
					else {
						ball++;
					}
				}

			}
		}

		if (strike == DIGIT)
		{
			printf("�����մϴ�. �����Դϴ�. �� �õ�Ƚ���� %d���Դϴ�.\n", count);
			break;
		}
		
		
		if (count == 5)
		{
			for (int i = 0; i < 3; i++)
			{
				if (user[i] == hint[0])
				{
					printf("%d�� Ȯ���� �����\n", user[i]);
					count--;
					break;
				}
				
			}
		}
		
		if (count == TRYCOUNT)
		{
			printf("������ �õ����׿�. ���ӿ���.\n");
			printf("���� : %d %d %d\n", computer[0], computer[1], computer[2]);
			break;
		}
		printf("%d %d %d�� %d��Ʈ����ũ %d���Դϴ�. %d��° �õ�����. ", user[0], user[1], user[2], strike, ball, count);
		printf("���� Ƚ�� :  %d\n", TRYCOUNT - count); 
		count++;
		}
	
	}
	


//���ھ߱� �ڵ带 § ����.
//1. �⺻������ ���ݴϴ�.
//2. ��ǻ���� �ƹ����� 3���� ������ �Է� ����3���� ���⿡ �迭�� �̿��Ͽ� 3�ڸ��� �����ݴϴ�.
//3. ������,�������ϱ�. ������ �������ڸ� �ǹ��ϸ�, ��ǻ�Ͱ� �����ٰ� �ε����� 0~9������ �����ϸ�,
//�̹� ���Դ� ���ڴ� �������ʰ� �ߺ�üũ�� ���ִ� �ڵ�.
//4. �����Ѵٴ� ������ ������ݴϴ�. �ݺ����� �̿��Ͽ� ������ ���ڸ����̻���
//�Է����� ���ϰ� �մϴ�.���� ������ �Է¼��ڰ� 0~9�� ���ڰ� �´���,�ߺ����� üũ.
//5.���� ������ �Է¼��� ��Ʈ����ũ/������ üũ�ϴ� �ڵ�
//6.��Ʈ����ũ���� �õ�Ƚ���� �������� ���󹮱��� �޶����°� �־��ݴϴ�.��!
//	

/*int a = scanf("%1d %1d %1d", &user[0], &user[1], &user[2]);
char c = getchar();
int b = scanf("%1d %1d %1d", &user[0], &user[1], &user[2]);
char d = getchar();*/

		//if (count == 5) {

			//	int hint = rand() % 10;
			//	while (1)
			//	{
			//		if (hint == computer[0] || hint == computer[1] || hint == computer[2]) 
			//		{
			//			break;
			//			//printf("��Ʈ: %d�� �����߿� �ϳ��Դϴ�. \n", hint);
			//		}
			//		hint = rand() % 10;
			//	}
			//	printf("%d�� Ȯ���� �־��\n", hint);
			//	
			//	
			//}