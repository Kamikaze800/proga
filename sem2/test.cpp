// № 6 Массив строк «Лекарства. Аптеки»
// Каждая строка содержит:
// - название лекарства;
// - страна-производитель;
// - дата производства;
// - номера аптек, имеющих это лекарство;
// - цена.
// Например:
// Анальгин Россия 21.02.08 7,9, 15 40.10
// Запрос: есть ли определенное лекарство с датой производства не ранее некоторой
// заданной и ценой не выше некоторой заданной.

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  

#define N 10    // Максимум строк
#define M 100     // Максимальная длина строки

int cmpDate(char* date,char* date_param){
    char* token = strtok(date_param, ".");
    int day_param = atoi(token);
    token = strtok(NULL, ".");
    int month_param = atoi(token);
    token = strtok(NULL, ".");
    int year_param = atoi(token);

    token = strtok(date, ".");
    int day = atoi(token);
    token = strtok(NULL, ".");
    int month = atoi(token);
    token = strtok(NULL, ".");
    int year = atoi(token);

    if (year>year_param){
        return 1;
    } else if(year==year_param && month > month_param){
        return 1;
    } else if(year==year_param && month==month_param && day>day_param){
        return 1;
    } else{
        return 0;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);;

    char ch; 
    char st[N][M];
    int i = 0, j = 0, k = 0;
    // FILE *file = fopen("lab2_1.txt", "r"); 
    int count_st = 0;
    i=0;
    fgets(st[i], M, stdin);
    // while(fgets(st[i], M, stdin)){
    //     st[i][strcspn(st[i], "\n")] = '\0';
    //     printf("%s\n", st[i]);
    //     i++;
    // }
    count_st = i;
    printf("%s", st[i]);
    printf("\nНажмите любую клавишу для повторения, Esc — выход...\n");
    _getch();
    return 0;
}
