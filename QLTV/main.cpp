#ifndef main_h
#define main_h
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "book.h"
#include "list.h"
#include "Node.h"
int main()
{
	List<Book> t;
	int chon;
	do
	{
		system("clear");
		cout<<"CHUONG TRINH QUAN LY THU VIEN"<<endl;
		cout<<"1. Them sach."<<endl;
		cout<<"2. Hien thi danh sach. "<<endl;
		cout<<"3. Luu xuong file. "<<endl;
		cout<<"4. Mo tu file. "<<endl;
		cout<<"5. Sua sach. "<<endl;
		cout<<"6. Xuat HTML. "<<endl;
		cout<<"0. Thoat."<<endl;
		cout<<"Moi ban chon: ";
		cin>>chon;
		switch(chon)
		{
			case 1:
			{
				ThemSach(t);
				break;
			}
			case 2:
			{
				HienThi(t);
				break;
			}
			case 3:
			{
				Savefile(t);
				break;
			}
			case 4:
			{
				LoadFile(t);
				break;
			}
			case 5:
			{
				SuaSach(t);
				break;
			}
			case 6:
			{
				Xuat_HTML(t);
				break;
			}
			case 0:
			{
				exit(0);
			}
		}
		cout<<"An ENTER de thoat!";
		cin.get();
		cin.get();
	}while(chon!=0);
	return 0;
}
#endif