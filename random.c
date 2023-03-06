#define _CRT_SECURE_NO_WARNINGS // scanf 그냥 쓸 수 있는 것, 맨 위에 써야 함
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{


	//1. 소스를 가기 전까지 다 이해를 하셔야 함 + 설명할 줄 알아야 함
	//2 draw.io에 가서 순서도를 그린다.
	//3. 총 9번 시도하고 3스트라이크가 그 안에 나오지 않으면 정답 출력하고 게임 오버 출력
	//4. 그 전에 3스트라이크가 나오면 게임 끝
	//5. 몇 번 만에 성공했는 지 알려주기
	//6. 궁극적으론 파일처리해서 랭킹까지 출력해보기
	//7. 랭킹 출력할 때 유저 이름 입력해서 그 걸 기록하게 하기



	//srand 랜덤 함수
	//int t = time(NULL); // : 시간 기준
	//srand(t); // rand에다가 현재 시간을 기준점을 잡아서 돌리는 것

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
		
		printf("정답 : ");
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
			printf("숫자 입력 하세요. 3개 한 번에 입력하시고 서로 중복되면 안 됩니다.\n");
			scanf("%d %d %d", &user[0], &user[1], &user[2]);
			if (user[0] == user[1] || user[0] == user[2] || user[1] == user[2]) //서로 중복된 경우
			{
				printf("중복 발견\n");
			}
			else
				break;

		}


		//입력할 떄 중복된 값이 있는 경우

		for (int i = 0; i < 3; i++)
		{
			if (computer[i] == user[i]) //자릿수랑 값이 다 똑같은 경우
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

		printf("%d 스트라이크 %d 볼\n", strike, ball);



	
	
	return 0;
}