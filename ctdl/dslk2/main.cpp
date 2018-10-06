#include <iostream>
using namespace std;
#include "list.h"

int main()
{
	List<int> T;
	T.addBack(1);
	T.addBack(2);
	T.addBack(3);
	T.addBack(4);
	//T.Delete();
	//T.Display();
	//T.Change(3,5);
	//T(5,10);
	//T.Display();
	//T.Insert(1,10);
	T.swap(2,3);
	cout<<"Max: "<<T.seachMax()<<endl<<"Size:"<<T.size()<<endl;
	T.Display();
	return 0;
}