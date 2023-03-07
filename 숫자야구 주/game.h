#pragma once
#define MAX_CHANCE 5//최대 시도 횟수를 상수로 정의한 매크로

void get_user_input(int user[]);//수는 유저로부터 3개의 정수를 입력받는 함수입니다. 
//이 함수는 입력된 수가 중복되는지 검사하고, 중복된 수가 있다면 유저로부터 다시 입력을 받습니다.
void play_game(int random[], int user[], int* chance, int* try_count, int* game_over);
//play_game() 함수는 랜덤으로 생성된 3개의 숫자와 유저가 입력한 3개의 숫자를 비교하여 결과를 출력하는 함수입니다. 
//결과는 strike와 ball로 나타내며, 정답을 맞출 때까지 유저에게 입력 기회를 주고, 최대 시도 횟수(MAX_CHANCE)가 지나면 게임을 종료합니다. 
//이 함수는 chance, try_count, game_over라는 3개의 포인터 매개변수를 사용하여 현재까지의 시도 횟수, 남은 기회, 게임 종료 여부를 저장하고 관리합니다.