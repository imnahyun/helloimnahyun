#pragma once
#define MAX_CHANCE 5
#define DIGIT 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_numbers(int random[], int not_random[]);
int get_user(int user[], char usernumber[]);
void play_game(int random[], int not_random[], int user[], int* chance, int* try_count, int* game_over);
