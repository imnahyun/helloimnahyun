#include"Dino_head.h"
#include "menu.h"
#include "baseball.h"




int main() {
    system("COLOR 0F");
    system("mode con cols=135 lines=50");

    playMusic("C:\\Users\\KB\\Desktop\\music.wav");

    printTxtFile("text.txt");
    CursorView(0);
    menu();
    system("cls");

    system("mode con cols=100 lines=25"); // �ܼ�â ũ�� ����
    printTxtFile("text.txt");
    printf("\n                                         ������ ����Ǿ����ϴ�.\n");

    return 0;
}