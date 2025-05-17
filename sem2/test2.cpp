// N41. ���������� ������������ ������ ����������� �����
// � 41 ������ ����� ����������� ����� ��������� �� ������
// ������ ������ ��������:
// ? ��� ���������;
// ? ���� �������� (���, �����, �����);
// ? ������������ �������������;
// ? ������ ��������� ������ (� ��������);
// ? ���� �� ������ ����������� (���������� ������ ���).
// ��������:
// ������ �.�. 1993,02,21 ��������������_����� 3210000 3
// ������: ���������� ��� ���� ���������� ������� �������������, ������� �� ������
// ������������� �������� � ����� ���� ������ �� ������ ����������� �� ����� ���������.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define N 10      // ������������ ����� �������
#define M 200     // ������������ ����� ������

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char st[N][M];
    char buf[100];
    int ch;

    do {
        // 1. ���� ������� �����
        int i = 0;
        printf("������� ������ � ���������� (���� ������ � ���� ���������):\n");
        printf("������:\n");
        printf("  [�������] [�.�.] [����,��,��] [�������������] [����� (���)] [����]\n");
        printf("������ ������ ��������� ����\n\n");
        while (i < N && fgets(st[i], M, stdin)) {
            if (st[i][0] == '\n') break;
            st[i][strcspn(st[i], "\n")] = '\0';
            i++;
        }
        int count = i;

        // 2. ���� ���������� �������
        int current_year, max_age, min_exp;
        char dept[M];

        // ������� ���
        while (1) {
            printf("\n������� ������� ���: ");
            fgets(buf, sizeof(buf), stdin);
            buf[strcspn(buf, "\n")] = '\0';
            if (strlen(buf) == 0) {
                printf("���� �� ����� ���� ������!\n");
                continue;
            }
            current_year = atoi(buf);
            if (current_year >= 1900 && current_year <= 2100) break;
            printf("������� ���������� ��� (1900�2100)\n");
        }

        // �������� �������������
        printf("������� �������� �������������: ");
        fgets(dept, sizeof(dept), stdin);
        dept[strcspn(dept, "\n")] = '\0';

        // ������������ �������
        while (1) {
            printf("������� ������������ �������: ");
            fgets(buf, sizeof(buf), stdin);
            buf[strcspn(buf, "\n")] = '\0';
            if (strlen(buf) == 0) {
                printf("���� �� ����� ���� ������!\n");
                continue;
            }
            max_age = atoi(buf);
            if (max_age > 0 && max_age < 200) break;
            printf("������� ������ ���� � ��������� 1�200\n");
        }

        // ����������� ����
        while (1) {
            printf("������� ����������� ���� ������: ");
            fgets(buf, sizeof(buf), stdin);
            buf[strcspn(buf, "\n")] = '\0';
            if (strlen(buf) == 0) {
                printf("���� �� ����� ���� ������!\n");
                continue;
            }
            min_exp = atoi(buf);
            if (min_exp >= 0) break;
            printf("���� ������ ������ ���� ���������������\n");
        }

        // 3. ��������� � ����� �����������
        printf("\n���������� ������������� \"%s\", �� ������ %d ��� � �� ������ �� ����� %d ���:\n\n",
               dept, max_age, min_exp);

        for (i = 0; i < count; i++) {
            char tmp[M];
            strcpy(tmp, st[i]);

            // �������� �� ����
            char* tok = strtok(tmp, " ");
            char* surname = tok;                              // �������
            tok = strtok(NULL, " ");
            char* initials = tok;                             // �.�.
            tok = strtok(NULL, " ");
            char* birth_str = tok;                            // "����,��,��"
            tok = strtok(NULL, " ");
            char* rec_dept = tok;                             // �������������
            tok = strtok(NULL, " ");
            int salary = atoi(tok);                           // ����� (�� ������������)
            tok = strtok(NULL, " ");
            int exp = atoi(tok);                              // ����

            // ������� ���� ��������
            int by, bm, bd;
            sscanf(birth_str, "%d,%d,%d", &by, &bm, &bd);

            int age = current_year - by;  // ���������� ��������

            if (strcmp(rec_dept, dept) == 0 && age <= max_age && exp >= min_exp) {
                printf("  %s %s\n", surname, initials);
            }
        }

        // 4. ����������� ��������� ������
        printf("\n������� ����� ������� ��� ������ ������� ��� ESC ��� ������\n");
        ch = _getch();
    } while (ch != 27);

    return 0;
}
