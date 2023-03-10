#include "game.h"

int main()
{
    int random[3];
    int hint[2];
    random_numbers(random, hint);

    int chance = MAX_CHANCE;
    int try_count = 1;
    int game_over = 0;
    int user[3];
    char usernumber[1024];

    while (!game_over && chance > 0)
    {
        printf("���� Ƚ��: %d\n\n", chance);
        get_user(user, usernumber);
        play_game(random, hint, user, &chance, &try_count, &game_over);

    }

    if (chance == 0)
    {
        printf("\n���� ����! %d���� �õ� ���� ������ ������ ���߽��ϴ�. \t������ %d%d%d�Դϴ�.\n", MAX_CHANCE, random[0], random[1], random[2]);
    }

    return 0;
}