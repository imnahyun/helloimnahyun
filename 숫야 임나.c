#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	
	int computer[3];
	int user[3];
	int i, j;
	int num;
	int count = 1;
	

	srand(time(NULL));


	for (i = 0; i < 3; i++) {
		num = rand() % 10;//0~9
		computer[i] = num;
		for (j = 0; j < i; j++) {
			if (computer[j] == computer[i]) {
				i--;
				break;

			}

		}

	}
	printf("���� 3���� �Է��Ͽ� ���ھ߱������� �غ��ÿ�!\n");

	
	while (1) {
		scanf("%1d %1d %1d", &user[0], &user[1], &user[2]);
		if (scanf("%1d %1d %1d", &user[0], &user[1], &user[2]) != 3) {
			printf("���ڸ� 3���� �Է����ּ���.\n");
			count--;
			continue;
		}
		else if (user[0] < 0 || user[0] > 9 || user[1] < 0 || user[1] > 9 || user[2] < 0 || user[2] > 9) {
			printf("0~9������ ���ڸ� �ϳ��� �Է��ؾ��մϴ�.\n");
			count--;
			continue;
		}
		else if (user[0] == user[1] || user[1] == user[2] || user[2] == user[0]) {
			printf("�ߺ��� �����Դϴ�\n");
			count--;
			continue;
		}
		

		int strike = 0, ball = 0;
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++)
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
		printf("%d %d %d�� %d��Ʈ����ũ %d���Դϴ�.\n", user[0], user[1], user[2], strike, ball);
		
		count++;
		for (count = 0; count <= 10; count++) {
			if (strike == 3) {
				printf("���� Ƚ������ ������ Ŭ�����߽��ϴ�!\n");
				break;
			}
			if (count == 10) {
				printf("���� Ŭ���� ����,Ƚ���ʰ�, ������ %d %d %d\n", computer[0], computer[1], computer[2]);
				break;
			}
			break;
		}
	
	}
}
		











//int count = 1;
//	  // �õ��ϴ� Ƚ��.�ö󰡴� Ƚ��.
//	for(count = 1; count < 11; count++) {
//		if (strike == 3) {
//			printf("���� Ƚ������ ������ Ŭ�����߽��ϴ�!");
//			break;
//		}
//		else if (count == 10) {
//			printf("���� Ŭ���� ����,Ƚ���ʰ�, ������ %d %d %d", computer[0], computer[1], computer[2]);
//			break;
//		}
//		break;
//	}


