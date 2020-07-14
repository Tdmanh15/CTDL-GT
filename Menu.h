#pragma once
#include<iostream>
#include<mylib.h>
#include<string>
using namespace std;
#define WHITE 15
#define BLACK 1
#define YELLOW 14
#define RED 4
#define BLUE 1
#define GREEN 2

const int so_item = 10;
const int dong = 5;
const int cot = 20;
const int SPACE = 32;
const int ENTER = 13;
const int ESC = 27;
const int BSPACE = 8;

const int Up = 72;
const int Down = 80;
#define MAXMH 300
#define MAXLOP 500
#define MAXmaMH 16
#define MAXtenMH 51
#define MAXmaSV 10
#define MAXS 50
#define MAX 10
#define MAXGT 4
// MON HOC - MANG CON TRO
struct MonHoc
{
	char MaMH[MAXmaMH];
	char TenMH[MAXtenMH];
};
struct dsMonHoc
{
	int n=0;
	MonHoc *MH[MAXMH];	// mang cho tro
};

// CAU DA THI
struct CauThi
{
	int id;
	char DapAn;
};
struct dsCauThi
{
	CauThi data;
	dsCauThi *next=NULL;
};
typedef dsCauThi *PTRCauThi;

// BAI THI
struct BaiThi
{
	int SoCau;
	int Tiem;
	PTRCauThi *cauthi;
};
// 	DIEM THI - DANH SACH LIEN KET DON
struct DiemThi
{
	char MaMH[MAXmaMH];
	float Diem;
	BaiThi BT;
};
struct dsDiemThi
{
	DiemThi data;
	dsDiemThi *next;	// danh sach lien ket don
};
typedef dsDiemThi *PTRDT;

// SINH VIEN - DANH SACH LIEN KET DON
struct SinhVien
{
	char MaSV[MAX];
	char Ho[MAXS], Ten[MAX], Phai[MAXGT];
	char Password[15];
	PTRDT DSDT = NULL; 	// con tro toi danh sach diem thi
};
struct dsSinhVien
{
	SinhVien data;
	dsSinhVien *next;	// danh sach lien ket don
};
typedef dsSinhVien *PTRSV;

// LOP - MANG CON TRO
struct Lop
{
	char MaLop[MAX];
	char TenLop[MAXS];
	char NienKhoa[MAX];
	PTRSV DSSV=NULL; 	// con tro toi danh sach sinh vien
};
struct dsLop
{
	int n=0;
	Lop *lop[MAXLOP];		// mang con tro
};

// CAU HOI THI - CAY NHI PHAN TIM KIEM
struct CauHoiThi
{
	int ID;
	char MaMH[MAXmaMH];
	string ND, A, B, C, D;
	char DapAn;
};
struct dsCauHoiThi
{
	CauHoiThi data;
	dsCauHoiThi *left;
	dsCauHoiThi *right;
};
typedef dsCauHoiThi *PTRCHT;

char MenuGV [so_item][MAXS]={"1. Nhap lop                            ",
					  "2. In danh sach lop theo nien khoa     ",
					  "3. Nhap sinh vien                      ",
					  "4. In danh sach sinh vien theo lop     ",
					  "5. Nhap mon hoc                        ",
					  "6. Nhap cau hoi thi                    ",
					  "7. Thi trac nghiem                     ",
					  "8. In cau hoi mon da thi cua sinh vien ",
					  "9. In bang diem                        ",
					  "10. Thoat                              "
};

char Menu1[so_item][MAXS]={"1. Them lop          ",
				   "2. Sua thong tin lop ",
				   "3. Xoa lop           ",
				   "4. Xem danh sach lop ",
				   "5. Quay lai          "
};

char Menu2[so_item][MAXS]={"1. Them sinh vien          ",
				   "2. Sua thong tin sinh vien ",
				   "3. Xoa sinh vien           ",
				   "4. Xem danh sach sinh vien ",
				   "5. Quay lai                ",
};

char Menu3[so_item][MAXS]={"1. Them mon hoc          ",
				   "2. Sua thong tin mon hoc ",
				   "3. Xoa mon hoc           ",
				   "4. Xem danh sach mon hoc ",
				   "5. Quay lai              ",
};

char Menu4[so_item][MAXS]={"1. Them cau hoi          ",
				   "2. Sua thong tin cau hoi ",
				   "3. Xoa cau hoi           ",
				   "4. Xem danh sach cau hoi ",
				   "5. Quay lai              ",
};
void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}
void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (10,24);
  cout <<s;
  Sleep(4000);
  gotoxy(10,24);
  clreol();
  gotoxy(x,y);
}
int MenuDong(char td [so_item][50]){
  Normal();
  system("cls");   int chon =0;
  int i; 
  for ( i=0; i< 10 ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  }  // end switch
  } while (1);
}


