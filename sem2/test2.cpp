// N41. Разработка программного модуля «Заработная плата»
// № 41 Массив строк «Заработная плата работника за месяц»
// Каждая строка содержит:
// ? ФИО работника;
// ? дата рождения (год, месяц, число);
// ? наименование подразделения;
// ? размер месячного оклада (в копейках);
// ? стаж на данном предприятии (количество полных лет).
// Например:
// Петров А.И. 1993,02,21 Вычислительный_центр 3210000 3
// Запрос: определить ФИО всех работников данного подразделения, которые не старше
// определенного возраста и имеют стаж работы на данном предприятии не менее заданного.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define N 10      // максимальное число записей
#define M 200     // максимальная длина строки

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char st[N][M];
    char buf[100];
    int ch;

    do {
        // 1. Ввод массива строк
        int i = 0;
        printf("Введите данные о работниках (одна строка — один сотрудник):\n");
        printf("Формат:\n");
        printf("  [Фамилия] [И.О.] [гггг,мм,дд] [Подразделение] [Оклад (коп)] [Стаж]\n");
        printf("Пустая строка завершает ввод\n\n");
        while (i < N && fgets(st[i], M, stdin)) {
            if (st[i][0] == '\n') break;
            st[i][strcspn(st[i], "\n")] = '\0';
            i++;
        }
        int count = i;

        // 2. Ввод параметров запроса
        int current_year, max_age, min_exp;
        char dept[M];

        // Текущий год
        while (1) {
            printf("\nВведите текущий год: ");
            fgets(buf, sizeof(buf), stdin);
            buf[strcspn(buf, "\n")] = '\0';
            if (strlen(buf) == 0) {
                printf("Поле не может быть пустым!\n");
                continue;
            }
            current_year = atoi(buf);
            if (current_year >= 1900 && current_year <= 2100) break;
            printf("Введите корректный год (1900–2100)\n");
        }

        // Название подразделения
        printf("Введите название подразделения: ");
        fgets(dept, sizeof(dept), stdin);
        dept[strcspn(dept, "\n")] = '\0';

        // Максимальный возраст
        while (1) {
            printf("Введите максимальный возраст: ");
            fgets(buf, sizeof(buf), stdin);
            buf[strcspn(buf, "\n")] = '\0';
            if (strlen(buf) == 0) {
                printf("Поле не может быть пустым!\n");
                continue;
            }
            max_age = atoi(buf);
            if (max_age > 0 && max_age < 200) break;
            printf("Возраст должен быть в диапазоне 1–200\n");
        }

        // Минимальный стаж
        while (1) {
            printf("Введите минимальный стаж работы: ");
            fgets(buf, sizeof(buf), stdin);
            buf[strcspn(buf, "\n")] = '\0';
            if (strlen(buf) == 0) {
                printf("Поле не может быть пустым!\n");
                continue;
            }
            min_exp = atoi(buf);
            if (min_exp >= 0) break;
            printf("Стаж работы должен быть неотрицательным\n");
        }

        // 3. Обработка и вывод результатов
        printf("\nСотрудники подразделения \"%s\", не старше %d лет и со стажем не менее %d лет:\n\n",
               dept, max_age, min_exp);

        for (i = 0; i < count; i++) {
            char tmp[M];
            strcpy(tmp, st[i]);

            // Разбивка на поля
            char* tok = strtok(tmp, " ");
            char* surname = tok;                              // Фамилия
            tok = strtok(NULL, " ");
            char* initials = tok;                             // И.О.
            tok = strtok(NULL, " ");
            char* birth_str = tok;                            // "гггг,мм,дд"
            tok = strtok(NULL, " ");
            char* rec_dept = tok;                             // Подразделение
            tok = strtok(NULL, " ");
            int salary = atoi(tok);                           // Оклад (не используется)
            tok = strtok(NULL, " ");
            int exp = atoi(tok);                              // Стаж

            // Парсинг года рождения
            int by, bm, bd;
            sscanf(birth_str, "%d,%d,%d", &by, &bm, &bd);

            int age = current_year - by;  // вычисление возраста

            if (strcmp(rec_dept, dept) == 0 && age <= max_age && exp >= min_exp) {
                printf("  %s %s\n", surname, initials);
            }
        }

        // 4. Возможность повторить запрос
        printf("\nНажмите любую клавишу для нового запроса или ESC для выхода\n");
        ch = _getch();
    } while (ch != 27);

    return 0;
}
