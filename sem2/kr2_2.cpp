#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s[100];
    do{fgets(s, sizeof(s), stdin);}while(s[0]=='\n');
    // �������� '\n'
    s[strcspn(s, "\n")] = '\0';

    int ln = (int)strlen(s);
    char *tok = strtok(s, "., ");
    int found = 0;

    while (tok != NULL) {
        printf("%s ", tok);
        if (strcmp(tok, "life") == 0) {
            found = 1;
        }
        tok = strtok(NULL, "., ");
    }

    printf("\n����� %d", ln);
    if (found) {
        printf("\n���� life");
    }

    _getch();
    return 0;
}
