#include"Dino_head.h"
#include"menu.h"
#pragma region �ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView()
{
    system("mode con:cols=100 lines=25"); //���� â�� ũ��
    system("title Google Dinosaurs. project_4Team"); //���� â�� ����
}
#pragma endregion

#pragma region Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
//WINDOWȯ�濡�� Console â���� ��µǴ� �ؽ��z�� Ŀ���� ��ġ�� �����ϴ� 'GotoXY'�� ����
{
    COORD Pos;
    //'COORD'�� Window API���� ���� �� ����ü�� x�� y��ǥ, Consoleâ���� Ŀ���� ��ġ�� ����
    Pos.X = 2 * x;//x�� ���� 2�� ����
    Pos.Y = y;//�״�� ����
    //Consoleâ���� �������� ���� ���̰� ����Ͽ� ǥ��
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
    //'SetConsoleCursorPosition'�Լ� ȣ��
    //�����ġ �ڵ�(GetStdHandle(STD_OUTPUT_HANDLE)�� ������ ���� ��ǥ��(Pos)�� ���ڷ� ����
    //Console â���� Ŀ���� ��ġ�� �ش� ��ǥ������ �̵�
}
#pragma endregion

#pragma region Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown()//Ű���� �Է��� �޾ƿ��� �Լ�
{
    if (_kbhit() != 0)//�Լ� ���ο��� ���Ǵ� '_kbit()'�Լ��� Ű���� buffer�� �Էµ� Ű �̺�Ʈ�� �ִ��� Ȯ���ϴ� �Լ�
        //Ű �Է��� �ִٸ� 0�� �ƴ� ���� ��ȯ
    {
        return _getch();//�Լ� '_getch'�� Ű���� ���ۿ��� ���� �Է��� �о���̴� �Լ�
        //�о���� Ű ��(ASCII�ڵ�)�� ��ȯ
    }
    return 0;
    //'_kibit()'�Լ��� 0�� ��ȯ�Ͽ� Ű���� ���ۿ� �Էµ� Ű �̺�Ʈ�� ���ٸ� �Լ��� '0'�� ��ȯ
}
/*���� 'GetKeyDown()'�Լ��� ���� �Էµ� Ű ���� ��ȯ�ϸ�, ���� �ƹ��� Ű �Է��� ���ٸ� 0�� ��ȯ
���Լ��� �̿��Ͽ� Ű �Է��� �����ϰ�, Ű���� �̺�Ʈ�� �����ϴ� ������ ������ �� ����.*/
#pragma endregion

#pragma region ������ �׸��� �Լ�
void DrawDino(int dinoY)//���� ����� ����ϴ� �Լ��� 'DrawDino'�� ����
//�Լ��� �Է°����� ������ y�� ��ġ(dinoY)�� �־�����, �� ��ġ�� ������ ���
{
    GotoXY(0, dinoY);//'GotoXY'�Լ��� ������ ��µ� ��ġ(0,dinoY)�� Ŀ���� �̵�
    static bool legFlag = true;
    //���� 'static bool legFlag' ���� ����, ������ �ٸ��� �����ư���, ����ϱ� ���� ������ ���
    printf("        $$$$$$$ \n");
    printf("       $$ $$$$$$\n");
    printf("       $$$$$$$$$\n");
    printf("$      $$$      \n");
    printf("$$     $$$$$$$  \n");
    printf("$$$   $$$$$     \n");
    printf(" $$  $$$$$$$$$$ \n");
    printf(" $$$$$$$$$$$    \n");
    printf("  $$$$$$$$$$    \n");
    printf("    $$$$$$$$    \n");
    printf("     $$$$$$     \n");
    if (legFlag)
    {
        printf("     $    $$$    \n");
        printf("     $$          ");
        legFlag = false;
    }
    else
    {
        printf("     $$$  $     \n");
        printf("          $$    ");
        legFlag = true;
    }
    //������ �ٸ��� �����ư��� ����ϱ� ����, 'legFlag' ������ ����Ͽ� ���� �ٸ��� ���¸� �����ϸ鼭 ���
    //���� 'legFlag'�� 'true'�̸�, ���� �ٸ��� ����ϰ� 'false'�̸� ������ �ٸ��� ���.
}
#pragma endregion

#pragma region ������ �׸��� �Լ�
void DrawTree(int treeX)
//����(Tree)����� ����ϴ� �Լ��� 'DrawTree'�� ����
//�Լ��� �Է°����� ������ x�� ��ġ(treeX)�� �־�����, �� ��ġ�� ������ ���
{
    GotoXY(treeX, TREE_BOTTOM_Y);
    printf("$$$$");
    GotoXY(treeX, TREE_BOTTOM_Y + 1);
    printf(" $$ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 2);
    printf(" $$ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 3);
    printf(" $$ ");
    GotoXY(treeX, TREE_BOTTOM_Y + 4);
    printf(" $$ ");
    //�Լ� ���ο����� GotoXY �Լ��� ȣ���Ͽ� ������ ��µ� ��ġ(treeX, TREE_BOTTOM_Y)�� Ŀ�� �̵�
    //'TREE_BOTTOM_Y'�� ������ �عٴ� ���̸� ��Ÿ���� ���
}
#pragma endregion

#pragma region �浹 ������ ���ӿ���
void DrawGameOver(const int score)
//'Game Over'�޼����� ����(score)�� ����ϴ� 'DrawGamOver'�� ����
//�Լ��� �Է°����� �÷��̾ ȸ���� ����(score)�� �־�����, 'GameOver'�޼��� ���
{
    system("cls");
    //�Լ� ���ο��� 'system("cls")'�Լ��� ����Ͽ� �ܼ� â�� �ʱ�ȭ
    int x = 18;
    int y = 8;
    GotoXY(x, y);
    printf("===========================");
    GotoXY(x, y + 1);
    printf("======G A M E O V E R======");
    GotoXY(x, y + 2);
    printf("===========================");
    GotoXY(x, y + 5);
    printf("SCORE : %d", score);
    //'GotoXY �Լ��� ȣ���Ͽ� �޼����� ��µ� ��ġ(x, y)�� Ŀ�� �̵�

    printf("\n\n\n\n\n\n\n\n\n");
    printf("�÷��̾� �̸��� �Է����ּ���(����θ�) : ");

    char name[50];
    scanf_s("%s", name, (unsigned)_countof(name));



    FILE* file = NULL;
    errno_t err = fopen_s(&file, "dino.txt", "a");
    if (err != 0)
    {
        printf("���� ���⿡ �����߽��ϴ�.");
        exit(1);
    }

    fprintf(file, "%s %d\n", name, score);
    fclose(file);

    printf("\n\n\n\n\n\n\n");
    printf("���ϴ� �޴��� �Է����ּ��� (r = �����, e = �޴�, w = ����) : ");

    char input;
    do
    {
        input = getchar();
    } while (input != 'r' && input != 'e' && input != 'w');

    if (input == 'r')
    {
        Dino_play();
    }
    else if (input == 'e')
    {
        system("cls");
        system("mode con cols=100 lines=40"); // �ܼ�â ũ�� ����
        playMusic("C:\\Users\\KB\\Desktop\\music.wav");
        printTxtFile("text.txt");
        menu();
    }

    else if (input == 'w')
    {
        system("mode con cols=100 lines=40"); // �ܼ�â ũ�� ����
        printTxtFile("text.txt");
        printf("\n                                         ������ ����Ǿ����ϴ�.\n");
        exit(0);
    }


    //'system("pause")' �Լ��� ����Ͽ� ����ڷκ��� Ű �Է��� ���
    //���� ���� �� Consoleâ�� ������� �ʰ�, ������� �Է��� ����ϴٰ� �ƹ� Ű�� ������ ���α׷��� ����
}
#pragma endregion

#pragma region �浹������ true, �ƴϸ� false
bool isCollision(const int treeX, const int dinoY)
//�浿 ������ �����ϴ� �Լ��� 'isCollision'�� ����
//�Է� ������ ������ ��ġ(treeX)�� ������ ����(dinoY)�� �̿��Ͽ�, �浹 ���� ����
{
    //Ʈ���� X�� ������ ��ü�ʿ� ������,
    //������ ���̰� ������� �ʴٸ� �浹�� ó��
    GotoXY(0, 0);
    //�Լ� ���ο��� 'GotoXY'�Լ��� ����Ͽ� ������� ���� �޼����� ���
    printf("treeX : %d, dinoY : %d", treeX, dinoY); //�̷������� ������ X, Y�� ã���ϴ�.
    //��� �޼����� ���� �⵿ ������ ���Ǵ� �Է� ������ treeX�� dinoY�� ����
    if (treeX <= 8 && treeX >= 4 && dinoY > 8)
        //'if'���� ����Ͽ� ������ ������ ��ġ�� �浹�ߴ��� ���� ����
        //�� �ڵ忡���� ������ X��ġ�� 4�̻� 8�����̰�,
        //������ ��ġ Y�� 8�̻��� �� �浹�� ����
        //�����ΰ� ���õ� ������, ������ �����ϴµ� ���� �ٸ� ������ ������ �� ����.
    {
        return true;
    }
    return false;
    //�浹 �߻� 'true', �׷��� ������ 'false'��ȯ
}
#pragma endregion
