#include <iostream>
#include <fstream>
#include "mylib.h"
using namespace std;

int main()
{
	int a=0; //tong so mon hoc trong kho mon hoc
	int c=0; //tong so mon da duoc nhap diem
	int chon;
	MonHoc mon[100];
	BangDiem bang[100];
	do
	{
		chon = menu();
		switch(chon)
		{
			case 1:
			{
				ThemMonHoc(mon,a);
				break;
			}
			case 2:
			{
				NhapDiem(bang,c,mon,a);
				break;
			}
			case 3:
			{
				XemBangDiem(bang,c);
				break;
			}
			case 4:
			{
				SuaDiem(bang,c);
				break;
			}
			case 5:
			{
				Luu_bang_diem_xuong_file(bang,c);
				break;
			}
			case 6:
			{
				ifstream filein;
				filein.open("data_mon_hoc.txt", ios_base::in); // mo file data_mon_hoc.txt ra
				Doc_file(filein,mon,a);
				filein.close();
				Xuat_data_mon_hoc(mon,a);
				break;
			}
			case 7:
			{
				ifstream filein;
				filein.open("Bang_Diem.txt", ios_base::in); // mo file data_mon_hoc.txt ra
				Doc_file_bang_diem(filein,bang,c);
				filein.close();
				Xuat_data_bang_diem(bang,c);
				break;	
			}
		}
	}while(chon!=0);
	
	return 0;
}