#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char ch;
do{   
    printf("Нажмите любую клавишу для повторения, Esc — выход...\n");
        ch = _getch(); // ждём клавишу
}while (ch != 27);
    return 0;
}
