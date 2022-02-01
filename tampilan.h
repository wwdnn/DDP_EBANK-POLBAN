

struct akun{
	char nama[100];
	char noRek[10];
	char password[50];
	int saldo; 
}ak, akn;

char filename[100],nama[50],password[50], noRek[10];
int jumlah; 

void gotoxy(int x, int y);
void lanjutkan(); 
void sambutan(); 
void daftar();
void masuk();
void menu(); 
void cekSaldo(); 
void deposit(); 
void modifikasiAkun(); 
void tutupAkun(); 
void transfer(); 
void keluar(); 
