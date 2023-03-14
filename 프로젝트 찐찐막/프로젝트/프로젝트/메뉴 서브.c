#include "menu.h"
#include "Dino_head.h"
#include <errno.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 100
#define NUM_SCORES 100

// �ܼ�â���� wav������ ����� ������ ����ҷ��� playsound�Լ��� �ʿ���.
// �̶� PlaySound �Լ��� wchar_t �������� �� ���ϰ�θ� �ν�
// charToWChar �Լ��� char������ ������ wchar_t�������� ��ȯ��Ű�� ���� ���� ��
// wchar_t�� �����ڵ� ���ڸ� �����ϱ� ���� ������ Ÿ����. 'char'Ÿ���� ���ڿ����� �ٸ� ���·� ���ڿ��� ǥ��

wchar_t* charToWChar(const char* str)
// const char*Ÿ���� ���ڿ��� wchar_t* Ÿ���� ���ڿ��� ��ȯ�ϴ� �Լ� ,�Լ��� �Ű������δ� const char*Ÿ���� ���ڿ� ������ str�� ���޵�
{
    const size_t size = strlen(str) + 1;
    // strlen �Լ��� ����Ͽ� ���ڿ� str�� ���̸� ����, �� ���̿� 1�� ���� ���ڿ��� ����� ����ũ�� ���
    wchar_t* wstr = (wchar_t*)calloc(size, sizeof(wchar_t));
    // calloc �Լ��� ����Ͽ� ���۸� �Ҵ�, �̶� �Ҵ�� �޸𸮸� 0���� �ʱ�ȭ
    mbstowcs_s(NULL, wstr, size, str, _TRUNCATE);
    // char ���ڿ��� wchar_t ���ڿ��� ��ȯ, ù��° �Ű����� NULL�� ��ȯ�� ���ڿ��� ���̸� ��ȯ,
    // �ι�° �Ű������� ��ȯ�� ���ڿ��� ������ ���ۿ� ���� ������(str�� wstr�� ����)
    // ����° �Ű����� size�� ������ ũ�⸦ ��Ÿ��
    // �׹�° �Ű����� str�� ��ȯ�� 'char'������ ���ڿ�
    // �ټ���° �Ű����� _TRUNCAT�� ��ȯ�� ���ڼ��� �ִ밪 = ���ڿ��� ���߸��� ��
    return wstr;
    // wchar_t�������� ��ȯ�� ���ڿ��� ��ȯ
}

// ���� �Լ��� ���� �Լ��� wav������ ��������� ��� �Լ�


void playMusic(const char* fileName)
// const char* fileName Ÿ���� ���ڿ� ������ fileName �Է��� ����
{
    wchar_t* wfileName = charToWChar(fileName);
    // �Է¹��� fileName ���ڿ��� wchar_t*Ÿ������ ��ȯ charToWChar�Լ����� mbstowcs�� �̿��Ͽ� ��ȯ
    PlaySound(wfileName, NULL, SND_FILENAME | SND_ASYNC);
    /*��ȯ�� wfileName�� �̿��Ͽ� Playsound()�Լ��� ȣ���� ����ϸ�,
    SND_FILENAME�� �̿��Ͽ� �����̸� �����ϰ� SND_ASYNC�� ����Ͽ� �񵿱������� ���*/
    free(wfileName);
    // ����� �Ǹ� free()�� �̿��Ͽ� ���ڿ��� �Ҵ�� �޸𸮸� ����
}



void printTxtFile(const char* fileName) {
    FILE* file;
    if (fopen_s(&file, fileName, "r") != 0) {
        printf("Failed to open file %s.\n", fileName);
        return;
    }

    char buffer[500];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
        fflush(stdout); // ��� ���۸� ����ݴϴ�.
    }
    printf("\n");
    printf("\n");
    printf("\n");
    fclose(file);
}

void read_and_sort_dino_data()
{
    // ���Ͽ��� ������ �б�
    FILE* fp_in;
    if (fopen_s(&fp_in, "dino.txt", "r") != 0) {
        printf("������ ������ �ʽ��ϴ�.");
        return;
    }

    int i, score[NUM_SCORES];
    char arr[NUM_SCORES][MAX_LEN];

    for (i = 0; i < NUM_SCORES; i++)
        fscanf_s(fp_in, "%s %d", arr[i], MAX_LEN, &score[i]);

    fclose(fp_in);

    // ������������ ����
    int j, temp;
    char temp_str[MAX_LEN];
    for (i = 0; i < NUM_SCORES - 1; i++) {
        for (j = 0; j < NUM_SCORES - i - 1; j++) {
            if (score[j] < score[j + 1]) {
                temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;

                strcpy_s(temp_str, MAX_LEN, arr[j]);
                strcpy_s(arr[j], MAX_LEN, arr[j + 1]);
                strcpy_s(arr[j + 1], MAX_LEN, temp_str);
            }
        }
    }

    // ���ĵ� ������ ���Ͽ� ����
    FILE* fp_out;
    if (fopen_s(&fp_out, "sorted_dino.txt", "w") != 0) {
        printf("������ ������ �ʽ��ϴ�.");
        return;
    }

    for (i = 0; i < NUM_SCORES; i++) {
        fprintf(fp_out, "%s %d\n", arr[i], score[i]);
    }

    fclose(fp_out);
}

void dinoscore()
{
    read_and_sort_dino_data();

    FILE* fp_in;
    if (fopen_s(&fp_in, "sorted_dino.txt", "r") != 0) {
        printf("������ ������ �ʽ��ϴ�.");
        return;
    }

    char name[MAX_LEN];
    int score;
    printf("<< ���� ���� >>\n");
    printf("Name\tScore\n");
    printf("--------------------\n");
    while (fscanf_s(fp_in, "%s %d", name, MAX_LEN, &score) == 2) {
        printf("%s\t%d\n", name, score);
    }

    fclose(fp_in);
}




void menu()
{
    int choice = 0;
    printf("\t\t                              ȯ���մϴ�!!!");
    printf("\n");
    printf("\n");



    while (1) {

        printf("\n");
        printf("\t�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�\n");
        printf("\t 1. ���ھ߱�");
        printf("       2. ��ֹ� ���ϱ�");
        printf("       3. ����");
        printf("       4. ��ŷ");
        printf("       5. ����\n\n");
        printf("\t�����ϼ��� : ");

        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");  // ȭ�� �ʱ�ȭ
            playMusic("C:\\Users\\KB\\Desktop\\music3.wav");
            // ���ھ߱� ���� �ڵ� ����

            break;
        case 2:
            system("cls");  // ȭ�� �ʱ�ȭ
            playMusic("C:\\Users\\KB\\Desktop\\music2.wav");
            Dino_play();
            break;
        case 3:
            system("cls");  // ȭ�� �ʱ�ȭ
            printf("���� ���� �߱����� �����ϰڽ��ϴ�.\n ");
            printf("������ �����ϸ� ������ 3�ڸ��� ���� ������ �˴ϴ�.\n ");
            printf("�־��� ��ȸ�� 10ȸ�̸� �ߺ��� ���ڸ� ������ �ƹ� ���� 3�ڸ��� �Է��Ͻø� �˴ϴ�.\n ");
            printf("�̶� �Է��� ���ڰ� �ڸ����� �ٸ��鼭 ���� ������ ���̸�, ���� �����鼭 �ڸ����� ������ ��Ʈ����ũ�� �˴ϴ�. \n ");// ����
            printf("\n");
            printf("���� ��� 815���� ������ �Ǿ��� �� 263���� �Է��� ���ô�.\n ");
            printf("������ ���ڿ� �Է��� ���ڿ��� ���� �ڸ��� ���� ���ڴ� �����Ƿ� 0���̸�, ���� ���ڰ� �ϳ��� �����Ƿ� 0��Ʈ����ũ �Դϴ�.\n ");// ����
            printf("�ٽ� 215�� �Է��� �غ���, ���� �ڸ��� ���� ���ڴ� 2���� �ְ� ���� ���ڰ� �����Ƿ� 2��Ʈ����ũ 0���� �Ǵ°̴ϴ�.\n "); // ����
            printf("���� ���������� 815�� �Է��ϸ� ���� �ڸ��� ���� �ڸ��� ���ڴ� 3���� �����Ƿ� 3��Ʈ����ũ�� �Ǹ� �÷��̾ �̱�ϴ�.\n "); // ����
            printf("�־��� ��ȸ�� 10ȸ�̹Ƿ� �����ϰ� ���ڸ� ��󺸼���.\n ");
            printf("\n");
            printf("\n");
            printf("��ֹ� ������ z ��ư�� ������\n");
            printf("�÷��̾��� ĳ���ʹ� ������ �ϰ� �ǰ� ��ֹ��� ���� �� �ֽ��ϴ�.\n");
            printf("��ֹ��� ���ؼ� �ְ������� ����غ�����.\n");
            break;
        case 4:
            system("cls");  // ȭ�� �ʱ�ȭ
            printTxtFile("text.txt");
            printf("\t�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�\n");
            printf("\t���ϴ� �޴��� ����ּ��� (1 = ���ھ߱� 2 = ��ֹ����ϱ� e = ���θ޴�) :");
            char input;
            do {
                input = getchar();
            } while (input != '1' && input != '2' && input != 'e' && input != 'r');

            if (input == '1')
            {
                system("cls");
                printTxtFile("baseball.txt");
            }
            else if (input == '2')
            {
                system("cls");
                printTxtFile("text.txt");
                // dino.txt ���Ͽ� ����� ������ ������������ �����ϴ� �ڵ�
                dinoscore();
            }
            else if (input == 'e')
            {
                system("cls");  // ȭ�� �ʱ�ȭ
                playMusic("C:\\Users\\KB\\Desktop\\music.wav");
                printTxtFile("text.txt");
                menu();
            }
            else
                printf("�߸��� �Է��Դϴ�.");
            break;
        case 5:
            system("cls");

            printTxtFile("text.txt");
            printf("\n                                         ������ ����Ǿ����ϴ�.\n");
            exit(0); // ���α׷� ����
        default:
            while (getchar() != '\n');
            system("cls");  // ȭ�� �ʱ�ȭ
            printTxtFile("text.txt");
            menu();
            break; // ���α׷� ����
        }
    }
}