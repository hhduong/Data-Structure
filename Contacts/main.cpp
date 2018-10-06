#ifndef main_h
#define main_h
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "contacts.h"
#include "list.h"
#include "Node.h"
int main()
{
	List<Contacts> t;
	int select;
	do 
	{
		system("clear");
		cout<<"---------------------------------"<<endl;
		cout<<"         ~ MY CONTACTS ~"<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"1. New contacts."<<endl;
		cout<<"2. Show contacts. "<<endl;
		cout<<"3. Seach contacts."<<endl;
		cout<<"4. Save contacts to file. "<<endl;
		cout<<"5. Upload contacts data from file."<<endl;
		cout<<"6. Edit contacts. "<<endl;
		cout<<"7. Export HTML file. "<<endl;
		cout<<"0. Exit."<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"=> Your choice: ";
		cin>>select;
		switch(select)
		{
			case 1:
			{
				New_contacts(t);
				break;
			}
			case 2:
			{
				Show_contacts(t);
				break;
			}
			case 3:
			{
				Seach_Contacts(t);
				break;
			}
			case 4:
			{
				Savefile(t);
				break;
			}
			case 5:
			{
				LoadFile(t);
				break;
			}
			case 6:
			{
				Edit(t);
				break;
			}
			case 7:
			{
				Export_HTML(t);
				break;
			}
			case 0:
			{
				exit(0);
			}
		}
		cout<<"Press Enter to exit!";
		cin.get();
		cin.get();
	}while(select!=0);
	return 0;
}
#endif