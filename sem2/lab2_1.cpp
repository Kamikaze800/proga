// № 48 Массив строк «Жилые дома»
// Каждая строка содержит:
// ? Наименование улицы;
// ? номер дома;
// ? год сдачи в эксплуатацию;
// ? площадь земельного участка;
// ? количество этажей;
// ? количество квартир;
// ? количество жильцов, зарегистрированных в доме.
// Например:
// Светлая 7 2018 10000 9 36 102
// Запрос: составить список домов (номера домов), сданных в эксплуатацию не позднее
// указанного года, имеющих площадь земельного участка не меньше заданной площади и
// количество жильцов - не больше заданного количества.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define N 10  // кол-во строк
#define M 100   // длина строки

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char st[N][M]; // массив строк
    int i = 0;
    int ch;
    do{
    printf("Введите данные о домах (одна строка — один дом):\n");
    printf("Формат: [улица] [номер] [год] [площадь] [этажей] [квартир] [жильцов]\n");
    printf("Пустая строка завершает ввод\n\n");

    while (i < N && fgets(st[i], M, stdin)) {
        if (st[i][0] == '\n') break;
        st[i][strcspn(st[i], "\n")] = '\0';
        i++;
    }
    int count = i;

    char buf[100]; // буфер для строкового ввода

    // Ввод параметров запроса
    int year_limit, area_limit, people_limit;

    // ===== Защищённый ввод: ГОД =====
    while (1) {
        printf("\nВведите максимальный год: ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';
        if (strlen(buf) == 0) {
            printf("Поле не может быть пустым!\n");
            continue;
        }
        year_limit = atoi(buf);
        if (year_limit > 1800 && year_limit < 2100) break;
        printf("Введите корректный год (от 1800 до 2100)\n");
    }
    
    // ===== Защищённый ввод: ПЛОЩАДЬ =====
    while (1) {
        printf("Введите минимальную площадь: ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';
        area_limit = atoi(buf);
        if (area_limit > 0) break;
        printf("Площадь должна быть положительным числом\n");
    }
    
    // ===== Защищённый ввод: КОЛ-ВО ЖИЛЬЦОВ =====
    while (1) {
        printf("Введите максимум жильцов: ");
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';
        people_limit = atoi(buf);
        if (people_limit > 0) break;
        printf("Число жильцов должно быть положительным\n");
    }
    

    printf("\nПодходящие дома (номера):\n");

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
            printf("Улица: %s, Дом №: %s\n", street, house_number);
        }
    }

    printf("\nНажмите любую клавишу, чтобы бы продолжить, либо ESC выхода\n");
    ch = _getch();
    }while(ch!=27);
    return 0;
}
