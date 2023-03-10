#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGIT 3 //총 자리수
#define LENGTH 4  //배열의 크기(3자리 문자열 입력해야 함
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
	printf("숫자 %d개를 입력하여 숫자야구게임을 해보시오!\n", DIGIT);
	
	
	
	while (1) {
		

		printf("%d 자리 수를 입력하세요.\n", DIGIT);
		gets(usernumber);
		//0자리, 1자리, 2자리, 4자리 이상이면 오류
		int digitCount = 0; //자릿수, 무조건 3이 나와야 함

		for (; digitCount < LENGTH; digitCount++)
		{
			if (usernumber[digitCount] == NULL)
			{
				break;
			}
		}
		if (digitCount != DIGIT)
		{
			printf("%d자리를 입력해야 합니다.\n", DIGIT);
			continue;
		}
		
		//세 자리가 정상적으로 들어왔다면 바꾸기
		for (int i = 0; i < DIGIT; i++)
		{
			user[i] = usernumber[i] - '0'; //각 글자들의 아스키값은 10을 넘는 수이므로
			//'0'만큼 빼서 이 글자들의 값이 0~9까지 되도록 하기
		}
	

		if (user[0] < 0 || user[0] > 9 || user[1] < 0 || user[1] > 9 || user[2] < 0 || user[2] > 9) {
			printf("0~9까지의 숫자를 하나만 입력해야합니다.\n");
			continue;
		}
		if (user[0] == user[1] || user[1] == user[2] || user[2] == user[0]) {
			printf("중복된 숫자입니다\n");
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
			printf("축하합니다. 정답입니다. 총 시도횟수는 %d번입니다.\n", count);
			break;
		}
		
		
		if (count == 5)
		{
			for (int i = 0; i < 3; i++)
			{
				if (user[i] == hint[0])
				{
					printf("%d는 확실히 없어요\n", user[i]);
					count--;
					break;
				}
				
			}
		}
		
		if (count == TRYCOUNT)
		{
			printf("마지막 시도였네요. 게임오버.\n");
			printf("정답 : %d %d %d\n", computer[0], computer[1], computer[2]);
			break;
		}
		printf("%d %d %d는 %d스트라이크 %d볼입니다. %d번째 시도예요. ", user[0], user[1], user[2], strike, ball, count);
		printf("남은 횟수 :  %d\n", TRYCOUNT - count); 
		count++;
		}
	
	}
	


//숫자야구 코드를 짠 순서.
//1. 기본세팅을 해줍니다.
//2. 컴퓨터의 아무숫자 3개와 유저의 입력 숫자3개가 들어가기에 배열을 이용하여 3자리를 정해줍니다.
//3. 시작전,난수정하기. 난수는 랜덤숫자를 의미하며, 컴퓨터가 정해줄각 인덱스에 0~9까지가 들어가야하며,
//이미 나왔던 숫자는 나오지않게 중복체크를 해주는 코드.
//4. 시작한다는 문구를 만들어줍니다. 반복문을 이용하여 유저가 세자리수이상을
//입력하지 못하게 합니다.또한 유저의 입력숫자가 0~9의 숫자가 맞는지,중복인지 체크.
//5.이제 유저의 입력수가 스트라이크/볼인지 체크하는 코드
//6.스트라이크인지 시도횟수가 몇인지에 따라문구가 달라지는걸 넣어줍니다.끝!
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
			//			//printf("힌트: %d는 정답중에 하나입니다. \n", hint);
			//		}
			//		hint = rand() % 10;
			//	}
			//	printf("%d는 확실히 있어요\n", hint);
			//	
			//	
			//}