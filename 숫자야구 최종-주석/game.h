#pragma once //�ѹ��� ���Եǵ��� ���ִ� ��� ���� ��ũ���Դϴ�.
#define MAX_CHANCE 10 //������ �ִ� �õ� Ƚ�������ϴ� ��ũ�� ����Դϴ�.
#define DIGIT 3 //������ ���� �ڸ����� 3���� �����ϴ� ��ũ�� ����Դϴ�.
#include <stdio.h> //ǥ������� ���̺귯���� �����մϴ�.
#include <stdlib.h> //�����Ҵ��� ���� ���̺귯���� �����մϴ�.
#include <time.h> //�ð� �Լ��� ����ϱ� ���� ���̺귯���� �����մϴ�.

void random_numbers(int random[], int hint[]);
//�� �Լ��� ������ ������ �����ϰ�, ��Ʈ�� ��ȯ�մϴ�.
int get_user(int user[], char usernumber[]);
//�� �Լ��� ����ڷκ��� �Է��� �޾� ������ ������ ���ڸ� ��ȯ�մϴ�.
void play_game(int random[], int hint[], int user[], int* chance, int* try_count, int* game_over);
// �Լ��� ������ ���� ��Ȳ�� �����ϰ�, ����� ����մϴ�. 
//�Է��� ���ڿ� ������ ���ϰ�, �õ� Ƚ���� ���� ���� ���θ� �����մϴ�.
