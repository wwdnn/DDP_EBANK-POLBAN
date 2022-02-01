#include "tampilan.h"
#include <stdio.h>
#include <windows.h>

int main(){
	system("cls");
	
		gotoxy(30,9); printf("              =======================");
		gotoxy(30,10);printf("               MOHON TUNGGU SEBENTAR");
		gotoxy(30,12);printf("              =======================");
		
		Sleep(500);
		gotoxy(30,11);printf("                     . ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
	
	sambutan(); 
	return 0;
}
