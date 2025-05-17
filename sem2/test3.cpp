#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char stroka[100];
    do{fgets(stroka, sizeof(stroka), stdin);}while(stroka[0] == '\n');
    // printf("%d", strlen(stroka));
    char *tok;
    tok = strtok(stroka, ",. ");
    char*str2;
    while(tok != NULL){
        str2 = tok;
        printf("%s ", tok);
        tok = strtok(NULL, ",. ");
    }
    strrev(str2);
    printf("%s", str2);    
    
    char ch = _getch();
    return 0;
}
