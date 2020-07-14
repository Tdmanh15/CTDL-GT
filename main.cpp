#include<iostream>
#include<stdio.h>
#include<conio.h>
#include "XuLy.h"
#include "Menu.h"
#include<string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;
void OpenFile(dsLop &ds, char *filename) { //list &ds
 FILE * f; //Sinhvien sv;
 Lop lop;
 if ((f=fopen(filename,"rb"))==NULL)
 {  BaoLoi ("Loi mo file de doc"); return ;
 }
 ds.n =0;
 while  (fread (&lop, sizeof (Lop), 1, f)!=0) {
 	ds.lop[ds.n]=new Lop;
 	*ds.lop[ds.n]=lop;
 	ds.n ++;
 }
    
 fclose(f);
 BaoLoi ("Da load xong danh sach vao bo nho");
}
int main(int argc, char** argv)
{
	dsLop ds;
	/*ds.lop[MAXLOP] = new Lop[MAXLOP];
	ifstream filein;
	filein.open("DanhSachLop.txt",ios_base::in);
	filein >> ds.n;
	cout<<ds.n;
	if(filein.fail() == true)
	{
		cout << "Khong doc duoc file!!" << endl;
		
	}
	for(int i=0;i<ds.n;i++)
	{
		cout<<"tNK";
		filein.getline(ds.lop[i]->MaLop,100,',');
		cout<<"NK";
		filein.getline(ds.lop[i]->TenLop,100,',');
		filein.getline(ds.lop[i]->NienKhoa,100);
	}*/
	
	OpenFile(ds,"DanhSachLop.txt");
	
	//PTRSV sv;
	//int dangnhap;
	//cout<<DangNhap();
	//cout<<MenuDong(MenuGV);
	/*dangnhap = DangNhap(ds,sv);
	if(dangnhap==0) cout<<"Bye Bye!!!!";
	else if(dangnhap==1)// Sinh Vien
	{
		
	}
	else // dangnhap == 2; Giao Vien
	{
		
	}*/
	//LoadDsLop(ds);
	//XuatDsLop(ds);
	
	
		/*for(int i=0;i<=n*3;i=i+3)
	{
		for(int j=0;j<=3;j++)
		{
			while(filein.eof()==false)
	{
			filein.getline(data,50);
		cout<<i<<" : data:  "<<data<<"\n";
		}}
		//filein.getline(data,50);
		//cout<<i<<" : data:  "<<data<<"\n";
		//cout<<i<<" : chuoi: "<<chuoi<<"\n";
	}*/
	
	
	cout<<"1";
	//filein.close();
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
	for (i = 0; i < ds.n; ++i)
	{
		if(i < 10)
			gotoxy(6, wherey());
		else
			gotoxy(5, wherey());
		cout << i + 1;
		gotoxy(13, wherey());
		cout << ds.lop[i]->TenLop;
		gotoxy(43, wherey());
		cout << ds.lop[i]->MaLop<<endl;
		gotoxy(50, wherey());
		cout << ds.lop[i]->NienKhoa<<endl;
	}
	return 0;
}
