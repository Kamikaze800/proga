// � 48 ������ ����� ������ ����
// ������ ������ ��������:
// ? ������������ �����;
// ? ����� ����;
// ? ��� ����� � ������������;
// ? ������� ���������� �������;
// ? ���������� ������;
// ? ���������� �������;
// ? ���������� �������, ������������������ � ����.
// ��������:
// ������� 7 2018 10000 9 36 102
// ������: ��������� ������ ����� (������ �����), ������� � ������������ �� �������
// ���������� ����, ������� ������� ���������� ������� �� ������ �������� ������� �
// ���������� ������� - �� ������ ��������� ����������.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define N 10  // ���-�� �����
#define M 100   // ����� ������

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char st[N][M]; // ������ �����
    int i = 0;
    int ch;
    do{
    printf("������� ������ � ����� (���� ������ � ���� ���):\n");
    printf("������: [�����] [�����] [���] [�������] [������] [�������] [�������]\n");
    printf("������ ������ ��������� ����\n\n");

    while (i < N && fgets(st[i], M, stdin)) {
        if (st[i][0] == '\n') break;
        st[i][strcspn(st[i], "\n")] = '\0';
        i++;
    }
    int count = i;

    char buf[100]; // ����� ��� ���������� �����

    // ���� ���������� �������
    int year_limit, area_limit, people_limit;

    // ===== ���������� ����: ��� =====
    while (1) {
        printf("\n������� ������������ ���: ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';
        if (strlen(buf) == 0) {
            printf("���� �� ����� ���� ������!\n");
            continue;
        }
        year_limit = atoi(buf);
        if (year_limit > 1800 && year_limit < 2100) break;
        printf("������� ���������� ��� (�� 1800 �� 2100)\n");
    }
    
    // ===== ���������� ����: ������� =====
    while (1) {
        printf("������� ����������� �������: ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';
        area_limit = atoi(buf);
        if (area_limit > 0) break;
        printf("������� ������ ���� ������������� ������\n");
    }
    
    // ===== ���������� ����: ���-�� ������� =====
    while (1) {
        printf("������� �������� �������: ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';
        people_limit = atoi(buf);
        if (people_limit > 0) break;
        printf("����� ������� ������ ���� �������������\n");
    }
    

    printf("\n���������� ���� (������):\n");

    for (i = 0; i < count; i++) {
        char line_copy[M];
        strcpy(line_copy, st[i]);

        char* token = strtok(line_copy, " ");
        char* street = token;

        token = strtok(NULL, " ");
        char* house_number = token;

        token = strtok(NULL, " ");
        int year = atoi(token);

        token = strtok(NULL, " ");
        int area = atoi(token);

        token = strtok(NULL, " ");
        int floors = atoi(token);

        token = strtok(NULL, " ");
        int apartments = atoi(token);

        token = strtok(NULL, " ");
        int people = atoi(token);

        if (year <= year_limit && area >= area_limit && people <= people_limit) {
            printf("�����: %s, ��� �: %s\n", street, house_number);
        }
    }

    printf("\n������� ����� �������, ����� �� ����������, ���� ESC ������\n");
    ch = _getch();
    }while(ch!=27);
    return 0;
}
