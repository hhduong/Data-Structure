#include <iostream>
using namespace std;
#include "list.h"
int main()
{
	List<int> ds;
	ds.Add(5);
	ds.Add(4);
	ds.Add(10);
	ds.Add(100);
	ds.Add(5);
	ds.Insert(3,50);

	//ds.Change(1,10);
	//ds.PrintAll();
	cout<<"So phan tu la: "<<ds.Count()<<endl;
	ds.PrintAll();
	ds.Delete(3);
	ds.PrintAll();
	cout<<"Phan tu 5 xuat hien "<<ds.Count(5)<<endl;
	cout<<"Phan tu co xuat hien trong lish ko? "<<ds.Seach(6)<<endl;
	cout<<"Phan tu lon nhat: "<<ds.SeachMax()<<endl;
	cout<<"Phan tu nho nhat: "<<ds.SeachMin()<<endl;
	ds.PrintAll();
	return 0;
}
