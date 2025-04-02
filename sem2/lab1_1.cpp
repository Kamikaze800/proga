//N16.
//Дан текст.Заменить все вхождения подстроки "del" на "Insert".Подсчитать
//количество замен для каждого отдельного слова, в котором была произведена замена.
//Пример.Исходный текст : "delete - нажмите клавишу deldel".
//Результат.Слово «delete» - 1 замена, слово «deldel» - 2 замены.
//Полученный текст : "Insertete - нажмите клавишу InsertInsert".

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h> 



int getLength(char arr[]) {
    int i = 0, j = 0;
    while (arr[i] != '\0') {
        i++;
    }
    return i;
}
int cmpStr(char* s1, char* s2, int len) {
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
void copyStr(char* s1, char* s2) {
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX_SIM_IN_TEXT = 500; 
    char* text; 
    char oldWord[] = "del";
    char newWord[] = "Insert";
    int oldLen = getLength(oldWord);
    int newLen = getLength(newWord);
    
    char ch;
    printf("\nпрограмма выполнена с использованием стандартных функций\n\
макс. кол-во символов в тексте %d\n\
del будето заменено на Insert\n", MAX_SIM_IN_TEXT);
    do {
        int i = 0, j = 0;
        text = (char*)malloc(MAX_SIM_IN_TEXT);
        printf("введите текст - ");
        while (((ch = getchar()) != '\n') && (i < MAX_SIM_IN_TEXT - 1)) {
            text[i] = ch;
            i += 1;
        }
        text[i] = ' ';
        text[i+1] = '\0';

        int globalCount = 0;
        char* word = (char*)malloc(MAX_SIM_IN_TEXT); 

        for (i = 0, j = 0; text[i] != '\0'; i++, j++) {
            word[j] = text[i]; 
            if (text[i] == ' ') {
                word[j] = '\0';
                int count = 0; 
                printf("в слове ");
                for (j = 0; word[j] != '\0'; j++)
                {
                    if (cmpStr(&word[j], oldWord, oldLen))
                        count++;
                    printf("%c", word[j]);
                }
                if (count == 1)
                    printf(" %d замена", count);
                else if(count == 2 || count == 3|| count ==4)
                    printf(" %d замены ", count);
                else
                    printf(" %d замен", count);
                printf("\n");
                globalCount += count;
                word[0] = '\0'; 
                j = -1;
           }
        }     

        int newTextL = (getLength(text) + globalCount * (newLen - oldLen) + 1);
        char* newText = (char*)malloc(newTextL);

        i = 0;
        while (text[i] != '\0') {
            if (cmpStr(&text[i], oldWord, oldLen)) { 

                copyStr(&newText[j], newWord); 
                i += oldLen; 
                j += newLen; 
            }
            else {
                newText[j++] = text[i++];
            }
        }
        newText[j] = '\0';

        printf("новый текст: ");
        for (i = 0; newText[i] != '\0'; i++) {
            printf("%c", newText[i]);
        }
        printf("\n");

        free(text);
        free(newText);


        printf("Для выхода нажмите Esc, для повторения любую клавишу...\n");
        ch = _getch();


    } while (ch != 27);
    return 0;
}
