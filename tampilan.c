#include "tampilan.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void lanjutkan(){
	
	printf("\n\n\t\t[1] MENU & [0] KELUAR : ");
	switch(getch()){
		case '1':
			menu();
			break;
		case '0':
			keluar();
			break;
		default :
			printf("\n\t\tINPUTAN SALAH (TEKAN ENTER!!)");
			getche();
			lanjutkan(); 	
	}
}
	
void sambutan(){

	int input;
	
	system("cls");
	
	gotoxy(1,1); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");
	gotoxy(30,2); printf("                   SELAMAT DATANG                         \n");
	gotoxy(30,3); printf("                         DI                               \n");
    gotoxy(30,4); printf("                    EBANK POLBAN                          \n");
    gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    gotoxy(1,6); printf("**********************************************************************************************************************\n");
    
    gotoxy(30,8);printf("                      1. MASUK                             \n");
    gotoxy(30,9);printf("                      2. DAFTAR                            \n");


    gotoxy(30,11); printf("          PILIHAN	: ");
    scanf("%d", &input);
    
    switch(input){
		case 1:
			masuk();
			break;
		
		case 2:
			daftar();
			break;
	}
}

void daftar(){
	FILE *data;
	
	system("cls");
	
	gotoxy(30,2); printf("                    ASIKK DAFTAR :)                          \n");
    gotoxy(1,3); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    gotoxy(1,4); printf("**********************************************************************************************************************\n");
    
    
	gotoxy(30,6); printf("     NO.REK / NIM\t: ");
	fflush(stdin);
	scanf("%s", &ak.noRek); 	

	gotoxy(30,7); printf("     NAMA        \t: ");
    fflush(stdin);
	scanf("%[^\n]", &ak.nama);
	    			
	gotoxy(30,8); printf("     PASSWORD    \t: ");
	fflush(stdin);  
	scanf("%[^\n]", &ak.password);
		
	ak.saldo = 0;
	
	strcpy(filename, ak.noRek); 
	data = fopen(strcat(filename, ".txt"), "w");
	fprintf(data, "%s;%s;%s;%d\n", ak.noRek, ak.nama, ak.password, ak.saldo);
	fclose(data); 	
	
	if(fwrite != 0){
		gotoxy(30,10); printf("                    BERHASIL :)                          \n");
		Sleep(1000); 
		masuk(); 
	}
}

void masuk(){
	FILE *fp; 
	
	system("cls");
	gotoxy(30,2); printf("                        HAI \n");
	gotoxy(30,3); printf("                  MAHASISWA POLBAN \n");
	
	Sleep(500);
	gotoxy(30,4); printf("                         :");	
	Sleep(500);
	printf(") \n\n");
	
	gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
	gotoxy(1,6); printf("**********************************************************************************************************************\n");
	
	gotoxy(30,8); printf("******************************************************\n");
	gotoxy(30,9); printf("                 | LOGIN DULU YUK |\n");	
	gotoxy(30,10); printf("******************************************************\n");
	
	gotoxy(30,12); printf("                 NO.REK   : ");
	scanf("%s", &noRek); 
	gotoxy(30,13); printf("                 PASSWORD : ");
	scanf("%s", &password); 
	
	fp = fopen(strcat(noRek, ".txt"), "r");
	if(fp == NULL){
		gotoxy(30,15);printf("            AKUN ANDA TIDAK TERSEDIA ^_^");
	} else {
		fscanf(fp, "%[^;];%[^;];%[^;];%d\n", ak.noRek, ak.nama, ak.password, &ak.saldo); 
		fclose(fp); 
		if(!strcmp(password, ak.password)){
			menu(); 
		}
	}
	
	
}

void menu(){
	int input;
	
	system("cls");
	
	gotoxy(30,2); printf("                     MENU UTAMA\n");
	gotoxy(30,3); printf("           ===============================\n");
    gotoxy(30,4); printf("               TEKAN <0> UNTUK BATAL\n\n");
    gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    gotoxy(1,6); printf("**********************************************************************************************************************\n");
   
    gotoxy(30,8);  printf("    1. MODIFIKASI AKUN           3. TUTUP AKUN\n");
    gotoxy(30,10); printf("    2. CEK SALDO                 4. DEPOSIT\n");
    gotoxy(30,12); printf("    5. TRANSFER                  6. KELUAR\n\n");
    
    printf("\n\n\nPILIHAN : "); 
	scanf("%d", &input);
	
	switch(input){
		case 1:   
			modifikasiAkun();
			break;
		case 2:
			cekSaldo(); 
			break;
		case 3:	
			tutupAkun(); 
			break;
		case 4:
			deposit(); 
			break;
		case 5:
			transfer(); 
			break;
		case 6:
			keluar(); 
			break; 
		case 0:
			break;	
	}
}

void cekSaldo(){
	
	
	system("cls");
	gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    gotoxy(1,6); printf("**********************************************************************************************************************\n");
    
    gotoxy(30,8);  printf("                SALDO ANDA   : Rp %d\n", ak.saldo);
   	lanjutkan(); 
 
}

void deposit(){
	FILE *fp;
	system("cls"); 
	gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    gotoxy(1,6); printf("**********************************************************************************************************************\n");
	
	gotoxy(30,8); printf("     DEPOSIT :\tRp ");
	fflush(stdin);
	scanf("%d", &jumlah); 		
	ak.saldo += jumlah;
	
	fp = fopen(noRek, "w");
	fprintf(fp, "%s;%s;%s;%d\n", ak.noRek, ak.nama, ak.password, ak.saldo);
	if(fwrite != 0){
		gotoxy(30,10); printf("     DEPOSIT BERHASIL SEBESAR Rp %d               \n", jumlah);
		fclose(fp); 
		lanjutkan(); 
	}
	
	
}

void modifikasiAkun(){
	int pilih; 
	FILE *fp;
	
	system("cls"); 
	gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    gotoxy(1,6); printf("**********************************************************************************************************************\n");
	gotoxy(30,12); printf("                 PASSWORD LAMA : ");
	scanf("%s", &password); 
	
	if(!strcmp(ak.password, password)){
		system("cls"); 
		gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
   		gotoxy(1,6); printf("**********************************************************************************************************************\n");
   		gotoxy(30,12); printf("      DATA NASABAH DENGAN NAMA : %s ", ak.nama);
		gotoxy(30,13); printf("      DATA YANG AKAN DIGANTI   :  ");
		gotoxy(30,14); printf("      1.	NAMA");
		gotoxy(30,15); printf("      2.	NO.REK");
		gotoxy(30,16); printf("      3.	PASSWORD");	
		printf("\n\n\nPILIHAN : "); 
		scanf("%d", &pilih);	

	
		if(pilih == 1){
			system("cls"); 
			gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
   			gotoxy(1,6); printf("**********************************************************************************************************************\n");
			gotoxy(30,12); printf("      NAMA NASABAH LAMA      : %s ", ak.nama);
			gotoxy(30,13); printf("      INPUT DATA NAMA BARU   : ");
			scanf("%s", nama);
			strcpy(ak.nama, nama);
			strcpy(filename, ak.noRek);
			fp = fopen(strcat(filename, ".txt"), "w");
			fprintf(fp, "%s;%s;%s;%d\n", ak.noRek, ak.nama, ak.password, ak.saldo);
			gotoxy(30,15); printf("      DATA NAMA BERHASIL DIUBAH :)");
			fclose(fp); 
		} else if (pilih == 2){
			system("cls"); 
			gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
   			gotoxy(1,6); printf("**********************************************************************************************************************\n");
			gotoxy(30,12); printf("      NO.REK NASABAH LAMA    : %s ", ak.noRek);
			gotoxy(30,13); printf("      INPUT NO.REK BARU      : ");
			scanf("%s", noRek);
			remove(strcat(ak.noRek, ".txt"));
			strcpy(ak.noRek, noRek);
			strcpy(filename, ak.noRek);
			fp = fopen(strcat(filename, ".txt"), "w");
			fprintf(fp, "%s;%s;%s;%d\n", ak.noRek, ak.nama, ak.password, ak.saldo);
			gotoxy(30,15); printf("      DATA NO.REK BERHASIL DIUBAH :)");
			fclose(fp); 
		} else if (pilih == 3){
			system("cls"); 
			gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
   			gotoxy(1,6); printf("**********************************************************************************************************************\n");
			gotoxy(30,12); printf("      PASSWORD NASABAH LAMA  : %s ", ak.password);
			gotoxy(30,13); printf("      INPUT PASSWORD BARU    : ");
			scanf("%s", password);
			strcpy(ak.password, password);
			strcpy(filename, ak.noRek); 
			fp = fopen(strcat(filename, ".txt"), "w");
			fprintf(fp, "%s;%s;%s;%d\n", ak.noRek, ak.nama, ak.password, ak.saldo);
			gotoxy(30,15); printf("      DATA PASSWORD BERHASIL DIUBAH :)");
			fclose(fp); 
		}
		
		lanjutkan(); 			
	}
}

void tutupAkun(){
	char pilih;
	bool pilihan = true;  
	FILE *fp; 
	
	system("cls"); 
	gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    gotoxy(1,6); printf("**********************************************************************************************************************\n");
	gotoxy(30,12); printf("                 PASSWORD      : ");
	scanf("%s", &password);
	
	if(!strcmp(ak.password, password)){
		system("cls"); 
		gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
   		gotoxy(1,6); printf("**********************************************************************************************************************\n");
   		gotoxy(30,12); printf("      DATA NASABAH DENGAN NAMA               : %s ", ak.nama);
		gotoxy(30,13); printf("      APAKAH ANDA YAKIN INGIN DIHAPUS [Y/N]  :  ");
		fflush(stdin); 
		scanf("%c", &pilih);
		
		while(pilihan){
			if(pilih == 'y' || pilih == 'Y'){
				remove(strcat(ak.noRek, ".txt")); 
				gotoxy(30,15); printf("      BERHASIL MENGHAPUS DATA NASABAH  "); 
				pilihan = false; 
			}
		}
		
		lanjutkan(); 
	}
}

void transfer(){
	FILE *fp, *fptr;
	
	system("cls"); 
	gotoxy(1,5); printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    gotoxy(1,6); printf("**********************************************************************************************************************\n");
	gotoxy(30,12); printf("                 NO.REK YANG DITUJU : ");
	scanf("%s", &noRek); 
	gotoxy(30,13); printf("                 NOMINAL TRANSFER   : Rp ");
	scanf("%d", &jumlah); 
	
	if(jumlah > ak.saldo){
		gotoxy(30,15); printf("                 MAAF SALDO ANDA TIDAK CUKUP ");
	} else {
		fptr = fopen(strcat(noRek,".txt"), "r");
		if(fptr == NULL){
			gotoxy(30,15);printf("            AKUN TERSEBUT TIDAK TERSEDIA ^_^");
		} else {
			fscanf(fptr, "%[^;];%[^;];%[^;];%d\n", akn.noRek, akn.nama, akn.password, &akn.saldo); 
			fclose(fptr);
			
			akn.saldo += jumlah;
			
			fptr = fopen(noRek, "w");
			fprintf(fptr, "%s;%s;%s;%d\n", akn.noRek, akn.nama, akn.password, akn.saldo);
			
			if(fwrite != 0){
				system("cls");
				gotoxy(30,10); printf("     TRANSFER BERHASIL SEBESAR Rp %d KEPADA %s               \n", jumlah, akn.nama);
				fclose(fptr);
				
				ak.saldo -= jumlah;
				strcpy(filename, ak.noRek);
				fp = fopen(strcat(filename, ".txt"), "w");
				fprintf(fp, "%s;%s;%s;%d\n", ak.noRek, ak.nama, ak.password, ak.saldo);
				fclose(fp); 
			}
		}
	}
	
	lanjutkan(); 
}

void keluar(){
	system("cls");
	gotoxy(30,9); printf("              ======================= ");
	gotoxy(30,10);printf("                       SAMPAI         ");
	gotoxy(30,11);printf("                    JUMPA KEMBALI     ");
	gotoxy(30,12);printf("              =======================\n\n");
}

