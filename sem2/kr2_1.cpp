#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

struct Student{
    char surname[100];
    int exams[5];
} students[30];

int main() {
     SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i, j, n, ex;
    printf("введите кол-во студентов\n");
    do{scanf("%d", &n);}while(n<1||n>30);

    printf("введите кол-во экзаменов\n");
    do{scanf("%d", &ex);}while(ex<1||ex>5);

    for(i=0;i<n;i++){
        printf("#%d)Фамилия: ", i);
        do{scanf("%s", &students[i].surname);}while(students[i].surname[0]=='\n');
        for(j=0;j<ex;j++){
            printf("    %d)", j);
            do{scanf("%d", &students[i].exams[j]);}while(students[i].exams[j]<0||students[i].exams[j]>5);
        }
    }

    for(i=0;i<n;i++){
        printf("#%d) Фамилия %s\n", i, students[i].surname);
        printf("оценки\n");
        for(j=0;j<ex;j++){
            printf("%d)%d ", j, students[i].exams[j]);}
        printf("\n");
    }

    int res1=0;
    printf("\nстуденты у которых свыше двух оченок(0 1 2)\n");
    for(i=0;i<n;i++){
        int k = 0, f1 = 0;
        for(j=0;j<ex;j++){
            if(students[i].exams[j]==0||students[i].exams[j]==1||students[i].exams[j]==2)f1=1;
            if(students[i].exams[j]!=4&&students[i].exams[j]!=5)k++;
        }
        if(f1)res1++;
        if(k>2)printf("%s\n", students[i].surname);
    }
    printf("\nкол-во студентов с хуевыми оценками: %d", res1);
    char ch = _getch();
    return 0;
}