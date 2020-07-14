#pragma once
#include"Menu.h"
#include<fstream>
using namespace std;

void LoadDsLop(dsLop &ds)
{
	int x;
	ifstream filein;
	filein.open("LopTemp.txt",ios_base::in);
	filein >> x;
	if(filein.fail() == true)
	{
		cout << "Khong doc duoc file!!" << endl;
		
	}
	ds.n=0;
	for(int i=0;i<x;i++)
	{
		ds.nodelop[i]=new Lop;
		getline(filein,ds.nodelop[i]->MaLop,',');
		getline(filein,ds.nodelop[i]->TenLop,',');
		getline(filein,ds.nodelop[i]->NienKhoa);
	}
	filein.close();
}

void XuatDsLop(dsLop ds)
{
	int x;
	ifstream filein;
	filein.open("LopTemp.txt",ios_base::in);
	filein >> x;
	int i;
	int y=wherey();
	gotoxy(5, y);
	cout << "STT";
	gotoxy(20, y);
	cout << "Ten lop";
	gotoxy(45, y);
	cout << "Ma lop";// << endl;
	gotoxy(60,y);
	cout<<"Nien Khoa"<<"\n";
	for (i = 0; i < x; ++i)
	{
		if(i < 10)
			gotoxy(6, wherey());
		else
			gotoxy(5, wherey());
		cout << i + 1;
		gotoxy(20, wherey());
		cout << ds.nodelop[i]->TenLop;
		gotoxy(45, wherey());
		cout << ds.nodelop[i]->MaLop<<endl;
		gotoxy(60, wherey()-1);
		cout << ds.nodelop[i]->NienKhoa<<endl;
	}
}
int NhapMa(char *x, int n_max)
{
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	char answer;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";	
			cout<<endl;		
			return ESC;
		}
		else if (c == ENTER)
		{
			if (i == 0){
				BaoLoi("Ban chua nhap thong tin, moi nhap lai!!");
				Sleep(2000);
				continue;
			}
			x[i] = '\0';
			cout << endl;
			return ENTER;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (c == SPACE){
			BaoLoi("Chuoi can nhap khong duoc chua khoang trang. Xin nhap lai");
			continue;		
		}
		else if (i == n_max){
			x1 = wherex();	y1 = wherey();
			x2 = wherex() + 5;	y2 = wherey() + 5;
			gotoxy(x2, y2);
			cout<<"Chuoi can nhap chi chua toi da " << n_max << " ki tu";
			Sleep(1000);
			gotoxy(x2, y2);
			cout <<"                                                                ";
			gotoxy(x1 , y1 );
			continue;
		}
		else if (c < 0){
			c = getch();
			if (c >= 0)
				continue;
		}
		else 
		{
			if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))// nhap chu, so
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu hoac so. Xin kiem tra lai!");
				continue;			
			}
		}
		if(c != 0){
		x[i] = c;
		cout << x[i];
		}
		++i;
	}
}

int NhapChuoi(char *x, int n_max)
{
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";
			cout<<endl;		
			return ESC;
		}
		else if (c == ENTER)
		{
			if (i == 0)
			{
				BaoLoi("Ban chua nhap chuoi, moi nhap lai!!");
				continue;
			}
			x[i] = '\0';
			cout << endl;
			return ENTER;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (i == n_max){
			x1 = wherex();	y1 = wherey();
			x2 = wherex()+5;	y2 = wherey()+5;
			gotoxy(x2,y2);
			cout<<"Chuoi can nhap chi chua toi da " << n_max << " ki tu";
			Sleep(1500);
			gotoxy(x2, y2);
			cout <<"                                                                ";
			gotoxy(x1, y1 );
			continue;
		}
		else if (i == 0 && c == SPACE)
		{
			BaoLoi("Ki tu dau tien khong duoc la khoang trang. Xin kiem tra lai!");
			continue;
		}
		else if (c < 0){
			c = getch();
			if(c >= 0)
			continue;
		}
		else 
		{
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == SPACE)// nhap chu
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu cai va dau cach. Xin kiem tra lai!");
				continue;			
			}
		}
		if (c != 0)
			cout<< x[i];
		++i;
	}
}

int NhapPass( char *x, int n_max)
{
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";
			cout<<endl;		
			break;
		}
	
		else if (c == ENTER)
		{
			if (i == 0){
				BaoLoi("Muc nay khong duoc de trong. Xin kiem tra lai");
				continue;
			}
			x[i] = '\0';
			cout << endl;
			break;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (c == SPACE){
			BaoLoi("Mat khau khong duoc chua khoang trang. Xin kiem tra lai!");
			continue;		
		}
		else if (i==n_max){
			x1=wherex();	y1=wherey();
			x2=wherex()+5;	y2=wherey()+5;
			gotoxy(x2,y2);
			cout<<"Chuoi can nhap chi chua toi da " << n_max << " ki tu";
			Sleep(2000);
			gotoxy(x2,y2);
			cout <<"                                                                ";
			gotoxy(x1 , y1 );
			continue;
		}
		else if (c < 0)
		{
			c = getch();
			if(c >= 0)
				continue;
		}
		else 
		{
			if (c >= 33 && c <= 126)// nhap chu, so, ki tu dac biet
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu hoac so. Xin kiem tra lai!");	
				continue;			
			}
		}
		if(c != 0)
		{
			x[i] = c;
			cout<<"*";
		}
		++i;
	}
}
PTRSV searchStudent(PTRSV First, char *masv)
{
	for(PTRSV p = First; p != NULL; p = p->next)
		if(stricmp(p->data.MaSV, masv) == 0)	return p;
	return NULL;
}
int DangNhap()
{
	//dsLop DSlop, PTRSV &sv
	dsLop DSlop; PTRSV sv;
	char *user = new char [10];
	char *pass = new char [8];
	int i = 0;
	PTRSV p;
	while(1)
	{
		system("cls");
		gotoxy(15,0);
		SetColor(14);
		cout<<"=======================DANG NHAP=======================";
		gotoxy(20,1);
		cout<<"Ten dang nhap: ";
		i = NhapMa(user, 10);
		if(i == ESC)
		{
			XoaDong(2, 2);
			cout << "Ban co muon thoat chuong trinh khong?(y/n) ";
			i = NhapMa(user, 2);
			if(i == ESC || user[0] == 'n' || user[0] == 'N')
				continue;
			else if(user[0] == 'y' || user[0] == 'Y')
				return 0;
		}
		else if(i == ENTER)
		{
			if(strlen(user) == 0)
			{
				cout << "Ban chua nhap thong tin! Moi nhap lai!" << endl;
				Sleep(2000);
				continue;
			}
			
		}
		gotoxy(20,2);
		cout<<"Nhap mat khau: ";
		i = NhapPass(pass, 8);
		if(i == ESC)
		{
			XoaDong(2, 2);
			cout << "Ban co muon thoat chuong trinh khong?(y/n) ";
			i = NhapMa(user, 2);
			if(i == ESC || user[0] == 'n' || user[0] == 'N')
				return 0;
			else if(user[0] == 'y' || user[0] == 'Y')
				break;
		}
		if(stricmp(user, "GV") == 0 || stricmp(user, "gv") == 0)
		{
			if(stricmp(pass, "GV") == 0 || stricmp(pass, "gv") == 0)
			{
				return 2;
			}
			else
			{
				cout << "Mat khau chua dung, moi nhap lai!!" << endl;
				Sleep(2000);
				continue;
			}
		}
		else
		{
			for(i = 0; i < DSlop.n; i++)
			{
				p = searchStudent(DSlop.nodelop[i]->DSSV, user);
				if(p != NULL)	break;
			}
			if(p == NULL)
			{
				cout << "User khong dung, moi nhap lai!!" << endl;
				Sleep(2000);
				continue;
			}
			else
				if(stricmp(pass, p->data.Password) == 0)
				{
					sv=p;
					return 1;
				}
				else
				{
					cout << "Mat khau khong dung! Moi nhap lai!" << endl;
					Sleep(2000);
					continue;
				}
		}
	}
	delete user;
	delete pass;
}

