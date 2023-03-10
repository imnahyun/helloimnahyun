#pragma once //한번만 포함되도록 해주는 헤더 가드 매크로입니다.
#define MAX_CHANCE 10 //게임의 최대 시도 횟수정의하는 매크로 상수입니다.
#define DIGIT 3 //게임의 숫자 자리수를 3으로 정의하는 매크로 상수입니다.
#include <stdio.h> //표준입출력 라이브러리를 포함합니다.
#include <stdlib.h> //동적할당을 위한 라이브러리를 포함합니다.
#include <time.h> //시간 함수를 사용하기 위한 라이브러리를 포함합니다.
int pitagoras(int a, int b);
int pitagorasptr(int* a, int* b);
void random_numbers(int r[], int h[]);
//이 함수는 게임의 정답을 생성하고, 힌트를 반환합니다.
void get_user(int u[], char un[]);
//이 함수는 사용자로부터 입력을 받아 유저의 선택한 숫자를 반환합니다.
void play_game(int rd[], int h[], int u[], int* c, int* t, int* g);
// 함수는 게임의 진행 상황을 관리하고, 결과를 출력합니다. 
//입력한 숫자와 정답을 비교하고, 시도 횟수와 게임 종료 여부를 관리합니다.

