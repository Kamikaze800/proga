//N48.
//��� �������� �����.��� ��������� ������ ���� A ��������(m * 2), ������ ���
//����� � ������ ������� - ������.����, � ������� � � ������ ������ ����� ���� ����, �,
//���� � �������� ������ ���� ������ �����, �� ��� ���� �������� �� ���������������
//������ �����.����� ��������� � ������ ����� ����� ���� ��������.

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  

#define MAX_STR_COUNT 5
#define MAX_WORD_LEN 10
#define MAX_SIM_IN_TEXT 500

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char A[MAX_STR_COUNT][2][MAX_WORD_LEN] = { // ������ �����
        {"del", "Insert"},
        {"old", "new"},
        {"cat", "dog"},
        {"hello", "hi"},
        {"world", "Earth"}
    };
    int size = sizeof(A) / sizeof(A[0]);
    char ch;
    // FILE *file = fopen("data.txt", "r"); 
    // fgets(text, MAX_SIM_IN_TEXT, file); 

    printf("��������� ��������� � �������������� ��������� �������\n\
�������� �������� - %d\n\
������ �����", MAX_SIM_IN_TEXT);
    for (int i = 0; i < size; i++) {
        printf("\n%s -> %s", A[i][0], A[i][1]);
    }
    printf("\n");
    do{
    printf("������� ����� - ");
    char* text = (char*)malloc(MAX_SIM_IN_TEXT);
    char* newText = (char*)malloc(MAX_SIM_IN_TEXT);    
    fgets(text, MAX_SIM_IN_TEXT, stdin);

    int i = 0, j = 0, k = 0;
    // j - ������ ��� ������� ������
    // k - ������ ��� ������ ������
    while(text[j] != '\0') {
        int replaced = 0; // ���� ������
        for(i=0; i<size; i++){
            if ((strncmp(&text[j], A[i][0], strlen(A[i][0])) == 0)){
                strncpy(&newText[k], A[i][1], strlen(A[i][1]));
                replaced = 1; // ����� ��������
                k += strlen(A[i][1]);
                j += strlen(A[i][0]);
                break;
            }
        }
        if (!replaced) {
            newText[k++] = text[j++];
        }
        newText[k] = '\0';
    }
    
    printf("����� �����: %s\n", newText);
    

    // fclose(file);
    free(text);
    free(newText); 

    printf("������� ����� ������� ��� ����������, Esc � �����...\n");
        ch = _getch(); // ��� �������
}while (ch != 27);
    return 0;
}
