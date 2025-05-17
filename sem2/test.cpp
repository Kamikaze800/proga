#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

struct Student
{
    char surname[16];
    int exam[5];
} student[30];

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, a, i, j;
    printf("Введите кол-во студентов\n");
    do {
        scanf("%d", &n);
    } while (n < 1 || n>30);
    while (getchar() != '\n');

    printf("\nВведите кол-во оценок\n");
    do {
        scanf("%d", &a);
    } while (a < 0 || a>5);
    while (getchar() != '\n');

    printf("Введите для каждого студента фамилию и оценки");

    for (i = 0; i < n; i++) {
        printf("\n#%d). Фамилия: ", i + 1);
        do {
            scanf("%s", &student[i].surname);
            while (getchar() != '\n');
        } while (student[i].surname[0] == '\n');

        for (j = 0; j < a; j++) {
            do {
                printf("        %d-оценка: ", j + 1);
                scanf("%d", &student[i].exam[j]);
                while (getchar() != '\n');
            } while (student[i].exam[j] < 0 || student[i].exam[j] > 5);
        }
    }

    printf("\nВывод массива:");

    for (i = 0; i < n; i++) {
        printf("\nСтудент: %-15s | Оценки: ", student[i].surname);
        for (j = 0; j < a; j++)
            printf("%d ", student[i].exam[j]);
    }

    printf("\n");

    int res1=0, res2=0;
    int f1, f2;
    for (i = 0; i < n; i++) {
        f1=1;
        f2=1;
        for (j = 0; j < a; j++){
            if(student[i].exam[j] != 4 && student[i].exam[j] != 5){
                f1 = 0;
                
            }
            if(student[i].exam[j] != 5){
                f2=0;
               
            }
        }
        if(f1)res1++;
        if(f2)res2++;
    }
    printf("кол-во студентов, у которых только 4 или 5: %d\n", res1);
    printf("кол-во студентов, у которых только 5: %d", res2);

    char ch = _getch();
    return 0;
}
